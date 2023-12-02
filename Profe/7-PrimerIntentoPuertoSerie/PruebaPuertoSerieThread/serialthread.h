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
#include <QTimer>

/*
 * Se definen una estructura frame_t para almacenar los datos de cada trama y
 * una unión charFrame_t que permite interpretar esos datos como un arreglo
 * de caracteres (char) para facilitar la lectura en archivos binarios. Esta
 * misma estructura se utiliza en el script de C utilizado para crear el archivo
 * a enviar por puerto serie.
*/
typedef struct
{
    // Byte de inicio.
    uint8_t start;
    // Contador.
    uint8_t count;
    // 8 entradas analógicas (12 bits).
    uint16_t a1in;
    uint16_t a2in;
    uint16_t a3in;
    uint16_t a4in;
    uint16_t a5in;
    uint16_t a6in;
    uint16_t a7in;
    uint16_t a8in;
    // 2 salidas analógicas.
    uint16_t a1out;
    uint16_t a2out;
    // 8 entradas digitales.
    uint8_t dIns;
    // 8 salidas digitales.
    uint8_t dOuts;

} frame_t;

/* Esta es una unión llamada charFrame_t que se utiliza para interpretar los
   datos de la estructura frame_t tanto como una estructura completa (tramaEntrada)
   como una matriz de caracteres (tramaEntradaChar). Esta unión se utiliza para
   manipular los datos en diferentes formatos.
*/
typedef union
{
    frame_t tramaEntrada;
    char    tramaEntradaChar[24];
} charFrame_t;


/* Clase llamada SerialReaderThread, que hereda de QThread. Esta clase se utiliza para
   leer datos desde un puerto serie en un hilo separado. Se configura para que cuando
   se reciban datos, emita una señal dataReceived que enviará la estructura charFrame_t
   con los datos.
*/
class serialThread : public QThread //Clase serialThread para el puerto serie
{
    Q_OBJECT

public:
    serialThread(const QString& portName, QObject* parent = nullptr); // Constructor
    ~serialThread();                                                  // Destructor
    void run() override;

signals:
    /* Esta es una señal que se emite cuando se reciben datos en el hilo SerialReaderThread.
       La señal lleva como argumento la estructura charFrame_t que contiene los datos recibidos.*/
    void dataReceived(const charFrame_t &data);

protected:
//    void run() override;    //funcion void run() donde se ejecuta el hilo

private:
    QSerialPort *serialPort; // Puntero para serialPort
    QByteArray data;        // Para recibir por puerto serie
    QByteArray dataBuffer;
    unsigned int bytesReceived;

};

#endif // SERIALTHREAD_H


