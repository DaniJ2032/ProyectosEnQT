#include "serialthread.h"

bool headerDetected = false;

/* Constructor */
serialThread::serialThread(QSerialPort* serialPort, QObject* parent) :
    QThread(parent), serialPort(serialPort){
    // Registrar el tipo de metadatos charFrame_t para su manejo en QT

    qRegisterMetaType<charFrame_t>("charFrame_t");
    qRegisterMetaType<charTxFrame_t>("charTxFrame_t");
}

/* Destructor */
serialThread::~serialThread() {

    if (serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
}

/* Funcion run() para la ejecucion del hilo*/
void serialThread::run() {

    if (!serialPort->open(QIODevice::ReadWrite)) {   //Si no se puede abrir el puerto serie
        qDebug() << "No se pudo abrir el puerto serie" << serialPort->portName()
                 << ":" << serialPort->errorString();
        return;
    }
    qDebug() << "Conectado al puerto serie" << serialPort->portName();

    dataBuffer.clear();
    bytesReceived = 0;

    while (!isInterruptionRequested()) {

        if (serialPort->waitForReadyRead(10)) {


            data = serialPort->read(1); // Lee la trama de a 24 byte

            if (!headerDetected) {  // Esta funcion se activa una sola vez
                // Si la cabecera no se ha detectado previamente, busca la cabecera en el búfer
                headerPos = dataBuffer.indexOf(header);
                if (headerPos != -1) {
                    // Cabecera encontrada
                    headerDetected = true;
                    dataBuffer = dataBuffer.mid(headerPos); // Elimina los datos anteriores a la cabecera
                }
            }
            if (!data.isEmpty()){
                dataBuffer.append(data);
                bytesReceived++;
                if (bytesReceived >= sizeof(frame_t)) {
                    if (dataBuffer.size() == sizeof(frame_t)) {
//                        qDebug() << "Tamaño trama: " << sizeof(frame_t);
//                        qDebug() << "\n Trama armada: " << dataBuffer;
                        memcpy(charData.tramaEntradaChar, dataBuffer.constData(), sizeof(frame_t));
                        emit dataReceived(charData); // Emite la trama recibida
//                       qDebug() << "\n Trama recibida: " << QByteArray(charData.tramaEntradaChar, sizeof(frame_t));
                        dataBuffer.clear();
                        bytesReceived = 0;
                        serialPort->clear();
                        headerDetected = false;
                    }
                }
            }

        }
        //Fin de if (serialPort->waitForReadyRead(1))
        usleep(1);
    }
    serialPort->clear();

} //fin del run()

/* reset de la bandera para la deteccion de la cabecera*/
void serialThread::resetHeaderDetection(){ headerDetected = false; }

/* Para testeo, se imprime la trama recibida */
QString serialThread::printToFrameRx(){

    QString  strFrame;
    uint8_t  uartCRC8 = charData.tramaEntrada.crc8;
    uint8_t  checkCRC8;
    checkCRC8 = codeCRC8((uint8_t *)&charData.tramaEntrada, sizeof (charData.tramaEntrada)-2);

    if (checkCRC8 == uartCRC8){
        strFrame.sprintf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", charData.tramaEntrada.start, charData.tramaEntrada.count,
                    charData.tramaEntrada.a1in, charData.tramaEntrada.a2in, charData.tramaEntrada.a3in, charData.tramaEntrada.a4in,
                    charData.tramaEntrada.a5in, charData.tramaEntrada.a6in, charData.tramaEntrada.a7in, charData.tramaEntrada.a8in,
                    charData.tramaEntrada.a1out, charData.tramaEntrada.a2out,
                    charData.tramaEntrada.dIns, charData.tramaEntrada.dOuts, charData.tramaEntrada.crc8);
        return strFrame;
    } else {
        QString crc8Text = QString("CRC8 recibido: %1  Calculado: %2").arg(uartCRC8).arg(checkCRC8);
       return strFrame;
    }
}

/* Para testeo, se imprime la trama enviada */
QString serialThread::printToFrameTx(){

    QString strFrameTx;

    strFrameTx.sprintf("Trama Enviada: %d %d %d %d %d %d \r\n", chartxData.tramaEnvio.start,
                    chartxData.tramaEnvio.count, chartxData.tramaEnvio.a1out,
                    chartxData.tramaEnvio.a2out, chartxData.tramaEnvio.dOuts, chartxData.tramaEnvio.crc8);
return strFrameTx;
}

/* Trama para transmitir */
void serialThread::frameTrasmiter(){

        static unsigned char countTx = 0;

        chartxData.tramaEnvio.start = 0x1B; // Cabecera
        chartxData.tramaEnvio.count = countTx;//countTx;  // Contador
        chartxData.tramaEnvio.a1out = DialA1;   // -> Tiene que venir del dial
        chartxData.tramaEnvio.a2out = DialA2;   // -> Tiene que venir del dial
        chartxData.tramaEnvio.dOuts = valorSalidasDigitales; // -> tiene que venir de botontes
        // Calcula y establece el CRC8
        chartxData.tramaEnvio.crc8 = codeCRC8((uint8_t *)&chartxData.tramaEnvio, sizeof (chartxData.tramaEnvio)-1);
        countTx++;

        QByteArray byteArray(reinterpret_cast<const char*>(&chartxData), sizeof(txFrame_t));

        if(serialPort->write(byteArray) == sizeof (txFrame_t)){
            emit dataTransmiter(chartxData);
        }
        else{
            qDebug() << "No se envio trama: " << byteArray;
        }
        while (serialPort->waitForBytesWritten(10)){}       
}

/* Lectura del valor de los botones */
void serialThread::readButtonValue(uint8_t* arrayBotones){

    valorSalidasDigitales = 0;
    for (int i = 0; i < numSalidasDigitales; i++ ) {
        uint8_t invertedValue = arrayBotones[i];    //Saque el negado
        // Use the inverted value to set the bits in valorSalidasDigitales
        valorSalidasDigitales |= (invertedValue & 0x01) << i;
    }
    frameTrasmiter();
}

/* Lectura de los valores de los Diales*/
void serialThread::readDialDAC(uint8_t value, uint8_t numDial){

    if(numDial == 0){
        DialA1 = value;
    }else if(numDial == 1){
        DialA2 = value;
    }else{
        qDebug() << "ERROR.";
    }

    frameTrasmiter();
}

/* Actualizacion de los display Analogicos*/
double* serialThread::updateADisplay(){

    static double voltage[8];
    float rangeanalogMax = 4095.0;
    float voltageMax = 10.0;

    voltage[0] = (static_cast<double>(charData.tramaEntrada.a1in) / rangeanalogMax) * voltageMax;
    voltage[1] = (static_cast<double>(charData.tramaEntrada.a2in) / rangeanalogMax) * voltageMax;
    voltage[2] = (static_cast<double>(charData.tramaEntrada.a3in) / rangeanalogMax) * voltageMax;
    voltage[3] = (static_cast<double>(charData.tramaEntrada.a4in) / rangeanalogMax) * voltageMax;
    voltage[4] = (static_cast<double>(charData.tramaEntrada.a5in) / rangeanalogMax) * voltageMax;
    voltage[5] = (static_cast<double>(charData.tramaEntrada.a6in) / rangeanalogMax) * voltageMax;
    voltage[6] = (static_cast<double>(charData.tramaEntrada.a7in) / rangeanalogMax) * voltageMax;
    voltage[7] = (static_cast<double>(charData.tramaEntrada.a8in) / rangeanalogMax) * voltageMax;

  return voltage;
}

/* Actualizacion de los display digitales */
bool* serialThread::updateDigDisplay(){

    static bool bits[8];

    for (int i = 0; i < 8; ++i) {
        bits[i] = (charData.tramaEntrada.dIns >> i) & 1;
    }
    return bits;
}

/* Obtencion del CRC8 */
uint8_t serialThread::codeCRC8(uint8_t *dataFrame, uint8_t longitud){

    uint8_t polinomio_generador = 0x07; // Polinomio generador CRC-8 (0x07)
    uint8_t reg_crc = 0; // Inicializa el registro CRC en cero

    for (uint8_t i = 0; i < longitud; i++) { // Se recorre la estructura
        reg_crc ^= dataFrame[i]; // Realiza un XOR con el byte actual

        for (uint8_t j = 0; j < 8; j++) {

            if (reg_crc & 0x80) {	// // Si el bit MSB = 1
                /*se realiza una operación XOR con el polinomio generador y se
                 * desplaza el registro CRC un bit a la izquierda*/
                reg_crc = (reg_crc << 1) ^ polinomio_generador;

             // Si el MSB = 0 Simplemente se desplaza 1 bit a la izquierda el reg_crc
            }else reg_crc <<= 1;
        }
    }

    return reg_crc;
}

