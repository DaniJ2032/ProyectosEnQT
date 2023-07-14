#include "duthread.h"

DuThread::DuThread(int tiempo, QObject *parent)
    : QThread(parent)
{
    mTiempo = tiempo;   //Igualo al tiempo
}

//Dentro de la redefinición de run se coloca lo que se desea que se ejecute con los hilos
void DuThread::run(){
    
    int contador = 0;
    while(true){
        if (contador ==100) contador = 0;   //cuenta hasta 100 y resetea
        
        emit ValorCambiado(contador);   //se emite una señal y a ValorCambiado se le manda el valor
        msleep(mTiempo);                //de contador cada vez que se actualiza
        ++contador;

    }
}
