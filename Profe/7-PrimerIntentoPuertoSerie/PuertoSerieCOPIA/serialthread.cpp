#include "serialthread.h"

serialThread::serialThread(const QString& portName, QObject* parent) :
    QThread(parent), serialPort(new QSerialPort(portName))
{
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

}   //fin de serialThread


serialThread::~serialThread()
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
}


void serialThread::run() {

    if (!serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << "No se pudo abrir el puerto serie" << serialPort->portName() << ":" << serialPort->errorString();
        return;
    }

    qDebug() << "Conectado al puerto serie" << serialPort->portName();

    while (!isInterruptionRequested()) {
        if (serialPort->waitForReadyRead(1000)) {
            data = serialPort->readAll(); // Lee la trama recibida

            qDebug() << "\n Trama recibida: " << data;
            emit dataReceived(data);
//            data.remove(0,24);

//            while(data.size() >= 24){
//                qDebug() << "\n Trama recibida: " << data;
//                emit dataReceived(data);
//                data.remove(0,24);
//            }

        }
    }

}

