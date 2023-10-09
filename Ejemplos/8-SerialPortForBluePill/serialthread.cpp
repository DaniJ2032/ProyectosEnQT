#include "serialthread.h"

/* El constructor de SerialReaderThread inicializa la instancia de la clase.
   Recibe el nombre del puerto serie al que se conectará y crea una instancia
   de QSerialPort configurada con la velocidad de baudios y otros parámetros.*/

serialThread::serialThread(const QString& portName, QObject* parent) :
    QThread(parent), serialPort(new QSerialPort(portName))
{
    //Configuracion del puerto serie
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Registrar el tipo de metadatos charFrame_t para su manejo en QT
    qRegisterMetaType<charFrame_t>("charFrame_t");
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

    if (!serialPort->open(QIODevice::ReadOnly)) {   //Si no se puede abrir el puerto serie
        qDebug() << "No se pudo abrir el puerto serie" << serialPort->portName()
                 << ":" << serialPort->errorString();
        return;
    }
    qDebug() << "Conectado al puerto serie" << serialPort->portName();

    frame_t receivedData;
    charFrame_t charData;

    dataBuffer.clear();
    bytesReceived = 0;

    while (!isInterruptionRequested()) {

        if (serialPort->waitForReadyRead(3000)) {

            data = serialPort->read(1); // Lee la trama de a 24 byte
            if (!data.isEmpty()){
                dataBuffer.append(data);
                bytesReceived++;
                if (bytesReceived >= sizeof(frame_t)) {
                    if (dataBuffer.size() == sizeof(frame_t)) {
                        qDebug() << "\n Trama armada: " << dataBuffer;
                        memcpy(&receivedData, dataBuffer.constData(), sizeof(frame_t));   //Copia la trama recibida a charData
                        memcpy(charData.tramaEntradaChar, dataBuffer.constData(), sizeof(frame_t));
                        emit dataReceived(charData); // Emite la trama recibida
//                        qDebug() << "\n Trama recibida: " << QByteArray(charData.tramaEntradaChar, sizeof(frame_t));
                        dataBuffer.clear();
                        bytesReceived = 0;
                    }
                }
            }
            // Imprime la trama almacenada en charData en la consola
//            qDebug() << "\n Trama recibida: " << QByteArray(charData.tramaEntradaChar, sizeof(frame_t));

        }
    }
} //fin del run()
