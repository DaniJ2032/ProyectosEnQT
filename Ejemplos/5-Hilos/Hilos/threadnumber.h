#ifndef THREADNUMBER_H
#define THREADNUMBER_H

#include <QThread>
#include <QMutex>

class ThreadNumber : public QThread
{
    Q_OBJECT
public:
    explicit ThreadNumber(QObject *parent = nullptr);

signals:
    void NewNumber(int);    //Señales son funciones que se ejecutan en los hilos

protected:
    void run(); //redefinición del run de QThread (aca se ejecuta el hilo)
    QMutex  mQMutex;    //Variable QMutex
};

#endif // THREADNUMBER_H
