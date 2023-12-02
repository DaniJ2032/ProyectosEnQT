
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
#include <structsTxAndRx.h> // Estructuras para envio y recepcion

class serialThread : public QThread //Clase serialThread para el puerto serie
{
    Q_OBJECT

public:
    serialThread(QSerialPort* serialPort, QObject* parent = nullptr); // Constructor
    ~serialThread();                    // Destructor
    void run() override;                // Funcion del hilo
    void resetHeaderDetection(void);    // Reset para la cabecera
    void frameTrasmiter(void);          // Armado de trama para envio
    QString printToFrameRx(void);       // Imprime la trama recibida
    QString printToFrameTx(void);       // Imprime la trama enviada

    void readButtonValue(uint8_t*);     // Lectura de los botones
    void readDialDAC(uint8_t, uint8_t); // Lectura de los Diales

    double* updateADisplay(void);       // Actualizacion de display analogicos
    bool* updateDigDisplay(void);       // Actualziacion de display digitales
    uint8_t codeCRC8(uint8_t *dataFrame, uint8_t longitud); //Generador de CRC8

signals:
    /* Esta es una señal que se emite cuando se reciben datos en el hilo SerialReaderThread.*/
    void dataReceived(const charFrame_t &data);
    void dataTransmiter(const charTxFrame_t &chartxData);

protected:
//    void run() override;

private:

    charTxFrame_t chartxData;
    QSerialPort *serialPort;                // Puntero para serialPort
    QByteArray data;                        // Para recibir por puerto serie
    QByteArray dataBuffer;                  // Buffer para los frames
    unsigned int bytesReceived;             //Contador de trama

    frame_t receivedData;                   // Para almacenar los frame recibidos
    charFrame_t charData;                   // Para almacenar los frame recibidos

    char header = '\x1B';                   // Cabecera de la trama
    int headerPos = -1;                     // Posición de la cabecera en el búfer

    const uint8_t numSalidasDigitales = 8;  // N de salidas digitales
    uint8_t valorSalidasDigitales = 0;      // Valor de saldias digitales
    uint8_t DialA1 = 0;                     // Dial PWM1
    uint8_t DialA2 = 0;                     // Dial PWM1
};

#endif // SERIALTHREAD_H
