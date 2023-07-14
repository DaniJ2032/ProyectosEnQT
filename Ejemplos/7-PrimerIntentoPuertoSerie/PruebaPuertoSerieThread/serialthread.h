#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMutex>
#include <QThread>
#include <QtDebug>

class serialThread : public QThread
{
    Q_OBJECT
public:
    serialThread(QObject *parent = nullptr);

signals:
    void dataReceived(const QByteArray& data);

protected:
    void run() override;

private:
    QSerialPort serialPort; //Objeto Serial
    QString cadena=""; //Cadena para recibir desde puerto
    QMutex mutex;
};

#endif // SERIALTHREAD_H
