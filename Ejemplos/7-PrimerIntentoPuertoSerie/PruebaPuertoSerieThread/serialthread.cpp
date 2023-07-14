#include "serialthread.h"

serialThread::serialThread(QObject *parent) : QThread(parent){

}   //fin de serialThread


void serialThread::run() {

if (!serialPort.isOpen()) {
    qDebug() << "El puerto serie no está abierto";
    return;
}

while (!isInterruptionRequested()) {
    if (serialPort.waitForReadyRead(1000)) {
        mutex.lock(); // Bloquea el mutex antes de acceder a la trama recibida

        QByteArray data = serialPort.readAll(); // Lee la trama recibida
        emit dataReceived(data);

        mutex.unlock(); // Desbloquea el mutex después de completar el acceso a la trama recibida
    }
}


}   //fin del run
