#ifndef STRUCTSTXANDRX_H
#define STRUCTSTXANDRX_H

#include <QObject>

// Struct para recepcion de frames
typedef struct {
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
    // codigo de redundancia ciclica 8
    uint8_t crc8;
} frame_t;

typedef union {
    frame_t tramaEntrada;
    char    tramaEntradaChar[25];
} charFrame_t;


// Struct para envio de frames
typedef struct {
    // Byte de inicio
    uint8_t start;
    // Contador.
    uint8_t count;
    // Saldias analog para PWM
    uint8_t a1out;
    uint8_t a2out;
    // Salidas Digitales
    uint8_t dOuts;
    // CRC-8
    uint8_t crc8;
} txFrame_t;

typedef union{
    txFrame_t tramaEnvio;
    char tramaEnvioChar[6];
} charTxFrame_t;


#endif // STRUCTSTXANDRX_H


