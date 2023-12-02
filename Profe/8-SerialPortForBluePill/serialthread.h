
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


    bool frameTrasmiter(void);


    uint8_t codeCRC8(uint8_t *dataFrame, uint8_t longitud);
    void readButtonValue(uint8_t*);
    void readDialDAC(uint8_t, uint8_t);
    double* updateADisplay();
    bool* updateDigDisplay();
    QString printToFrameTx();
    QString printToFrameRx();

    void bufferclear();

signals:
    /* Esta es una señal que se emite cuando se reciben datos en el hilo SerialReaderThread.
       La señal lleva como argumento la estructura charFrame_t que contiene los datos recibidos.*/

    void dataReceived(const charFrame_t &data);
    void dataTransmiter(const charTxFrame_t &chartxData);

protected:
//    void run() override;    //funcion void run() donde se ejecuta el hilo

private:


    charTxFrame_t chartxData;

    QSerialPort *serialPort; // Puntero para serialPort
    QByteArray data;        // Para recibir por puerto serie
    unsigned int bytesReceived; //Contador de trama

    frame_t receivedData;   // Para almacenar los frame recibidos
    charFrame_t charData;   // Para almacenar los frame recibidos

    char header = '\x1B';   // Cabecera de la trama
    int headerPos = -1;     // Posición de la cabecera en el búfer
    bool generateFrameTx = true;

    const uint8_t numSalidasDigitales = 8;

    uint8_t valorSalidasDigitales = 0;

    uint8_t DialA1 = 0;
    uint8_t DialA2 = 0;
};

#endif // SERIALTHREAD_H


