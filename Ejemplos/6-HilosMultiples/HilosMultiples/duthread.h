#ifndef DUTHREAD_H
#define DUTHREAD_H
#include<QThread>

class DuThread : public QThread
{
    Q_OBJECT
public:
    DuThread(int tiempo, QObject *parent = nullptr); //Agrega la variable tiempo

signals:
void ValorCambiado(int);    //Cambio de valor

protected:
void run() override;        //sobrecarga y redefinición de la funcion run

private:
    int mTiempo; //milisegundos
};

#endif // DUTHREAD_H
