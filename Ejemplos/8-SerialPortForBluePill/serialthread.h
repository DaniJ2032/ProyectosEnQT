/*#########################################################################################*/
/*##                                    Head del hijo                                    ##*/
/*##-------------------------------------------------------------------------------------##*/
/*## Esta cabecera pertenece a la clase hija, la cual se encarga de gestionar un hilo de ##*/
/*## trabajo que recibe por puerto serie los datos que se le envia y luego pasarlos      ##*/
/*## al padre para poder imprimir en pantralla lo recibido y almacenarlo.                ##*/
/*## El manejo de hilos permite trabajar con datos en paralelo sin tener que detener     ##*/
/*## procesos principales del propio script como son en este caso los botones y pantalla ##*/
/*## los hilos procesan los datos y luego los libera para la rama principal.             ##*/
/*## esto se logra con el uso de la libreria <QThread> y su funcion void run() override  ##*/
/*## la cual dentro de la misma se coloca lo que se quiere ejecutar en el hilo.          ##*/
/*## se puede utilizar multiples hilos, y en ese caso se recomienda el uso de <QMutex>   ##*/
/*## para bloquear datos y evitar interferencia entre dos hilos que quieran usarlo       ##*/
/*#########################################################################################*/

#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

//Librerias del proyecto
#include <QObject>
#include <QApplication>
#include <QtSerialPort/QSerialPort> //Serial port
#include <QtSerialPort/QSerialPortInfo>

#include <QMutex>   // Bloqueo de datos
#include <QThread>  // Manejo de hilos
#include <QtDebug>  // Imprimir datos en consola
#include <QFile>    // Guardado de datos en archivos
#include <QTextStream> // manejo de datos en los archivos
#include <QString>
#include <structsTxAndRx.h> // Estructuras para envio y recepcion

/* Clase llamada SerialReaderThread, que hereda de QThread. Esta clase se utiliza para
   leer datos desde un puerto serie en un hilo separado. Se configura para que cuando
   se reciban datos, emita una señal dataReceived que enviará la estructura charFrame_t
   con los datos.
*/
class serialThread : public QThread //Clase serialThread para el puerto serie
{
    Q_OBJECT

public:
    serialThread(QSerialPort* serialPort, QObject* parent = nullptr); // Constructor
    ~serialThread();                                                  // Destructor
    void run() override;
    void frameHeaderOK(QByteArray data);    //Retorna TRUE si encontro cabecera
    void resetHeaderDetection();            //Reset del detector de cabecera
    bool frameTrasmiter(void);

signals:
    /* Esta es una señal que se emite cuando se reciben datos en el hilo SerialReaderThread.
       La señal lleva como argumento la estructura charFrame_t que contiene los datos recibidos.*/
    void dataReceived(const charFrame_t &data);
    void dataTransmiter(const charTxFrame_t &data);

protected:
//    void run() override;    //funcion void run() donde se ejecuta el hilo

private:

//    txFrame_t txData;
    charTxFrame_t chartxData;

    QSerialPort *serialPort; // Puntero para serialPort
    QByteArray data;        // Para recibir por puerto serie
    QByteArray dataBuffer;  // Buffer para los frames
    unsigned int bytesReceived; //Contador de trama

    frame_t receivedData;   // Para almacenar los frame recibidos
    charFrame_t charData;   // Para almacenar los frame recibidos

    char header = '\x1B';   // Cabecera de la trama
    int headerPos = -1;     // Posición de la cabecera en el búfer
    bool generateFrameTx = true;


};

#endif // SERIALTHREAD_H


