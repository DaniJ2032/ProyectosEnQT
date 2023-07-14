#include "threadnumber.h"

ThreadNumber::ThreadNumber(QObject *parent) : QThread(parent)
{

}

void ThreadNumber :: run(){

    mQMutex.lock();
    for (int i = 0; i<1000000; i++){
        emit NewNumber(i);
        msleep(100);
    }
    mQMutex.unlock();
}
