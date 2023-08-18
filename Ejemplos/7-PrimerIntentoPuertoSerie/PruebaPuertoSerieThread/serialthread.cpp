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
            mutex.lock(); // Bloquea el mutex antes de acceder a la trama recibida
            data = serialPort->readAll(); // Lee la trama recibida
            msleep(10);
            qDebug() << "Trama recibida: " << data;
//            emit dataReceived(data);
            mutex.unlock(); // Desbloquea el mutex después de completar el acceso a la trama recibida
            emit dataReceived(data);
            data = "";
        }
    }

}

