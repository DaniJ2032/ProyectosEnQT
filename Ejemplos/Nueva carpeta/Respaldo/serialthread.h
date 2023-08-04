#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QObject>
#include <QApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMutex>
#include <QThread>
#include <QtDebug>



class serialThread : public QThread
{
    Q_OBJECT

public:
    serialThread(const QString& portName, QObject* parent = nullptr);
    ~serialThread();
    void run() override;

signals:
    void dataReceived(const QByteArray &data);

//protected:
//    void run() override;

private:
    QSerialPort* serialPort;
    QByteArray data; //Cadena para recibir desde puerto
    QMutex mutex;
};

#endif // SERIALTHREAD_H
