#include "serialthread.h"

bool headerDetected = false;


/* El constructor de SerialReaderThread inicializa la instancia de la clase.
   Recibe el nombre del puerto serie al que se conectará y crea una instancia
   de QSerialPort configurada con la velocidad de baudios y otros parámetros.*/

serialThread::serialThread(QSerialPort* serialPort, QObject* parent) :
    QThread(parent), serialPort(serialPort){


    // Registrar el tipo de metadatos charFrame_t para su manejo en QT
    qRegisterMetaType<charFrame_t>("charFrame_t");
    qRegisterMetaType<charTxFrame_t>("charTxFrame_t");

}

/* El destructor de SerialReaderThread se encarga de cerrar el puerto serie si está abierto
   y eliminar la instancia de QSerialPort cuando el objeto se destruye.*/
serialThread::~serialThread()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
}

/* Este método es el punto de entrada del hilo SerialReaderThread. Aquí se configura el puerto
   serie y se inicia la lectura de datos desde el puerto serie. Cuando se reciben datos, se
   emite la señal dataReceived para que otros objetos puedan procesarlos.*/
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
        if (frameTrasmiter()){

            generateFrameTx = false;

            data = serialPort->read(1); // Lee la trama de a 24 byte
//            qDebug() << data;

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
                        memcpy(&receivedData, dataBuffer.constData(), sizeof(frame_t));   //Copia la trama recibida a charData
                        memcpy(charData.tramaEntradaChar, dataBuffer.constData(), sizeof(frame_t));
                        // DEBERIA MOVER ACA EL CRC8
                        emit dataReceived(charData); // Emite la trama recibida
//                        qDebug() << "\n Trama recibida: " << QByteArray(charData.tramaEntradaChar, sizeof(frame_t));
                        dataBuffer.clear();
                        bytesReceived = 0;
                        generateFrameTx = true;
                    }
                }
            }

        }

        } //Fin de if (serialPort->waitForReadyRead(1))
    }

    serialPort->close();
} //fin del run()


void serialThread::resetHeaderDetection(){ headerDetected = false; }

bool serialThread::frameTrasmiter(void){



    if(generateFrameTx){
        static unsigned char countTx = 0;
        chartxData.tramaEnvio.start = 0x1B; // Cabecera
        chartxData.tramaEnvio.count = countTx;  // Contador
        chartxData.tramaEnvio.a1out = 0x05;   // -> Tiene que venir del dial
        chartxData.tramaEnvio.a2out = 0x06;   // -> Tiene que venir del dial
        chartxData.tramaEnvio.dOuts = 0x07; // -> tiene que venir de botontes
        // Calcula y establece el CRC8
        chartxData.tramaEnvio.crc8 = 0xFF;
        countTx++;

        QByteArray byteArray(reinterpret_cast<const char*>(&chartxData), sizeof(txFrame_t));

        if(serialPort->write(byteArray) == sizeof (txFrame_t)){
            emit dataTransmiter(chartxData);

        qDebug() << "Enviando trama: " << byteArray;

        }else{
            return false;
        }
        while (serialPort->waitForBytesWritten(10)){}

    }

    return true;
}

