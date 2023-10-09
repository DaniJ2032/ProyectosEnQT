/*#########################################################################################*/
/*##                                   TP de interfaz QT                                 ##*/
/*##-------------------------------------------------------------------------------------##*/
/*## Para el siguiente trabajo práctico, se realizo un Widget en QT el cual toma  datos  ##*/
/*## desde el puerto serie y los procesa para obtener cada frame enviado por un script   ##*/
/*## en C. Dischos frame posee la siguiente escructura:                                  ##*/
/*##                                                                                     ##*/
/*## Trama: start,count,aIn1,aIn2,aIn3,aIn4,aIn5,aIn6,aIn7,aIn8,aOut1,aOut2,dIn,dOut,    ##*/
/*## en donde:                                                                           ##*/
/*## start --> Cabecera y siempre vale (0x1b)                                            ##*/
/*## count --> Contador que indica el numero de frame recibido                           ##*/
/*## aIn1 al aIn8 --> Entradas analógicas cuyos valores van desde 0 a 4095               ##*/
/*## aOut1 a aOut2 --> Salidas analógicas cuyos valores van desde 0 a 4095               ##*/
/*## dIn --> 8 entradas digitales del sistema cuyos valores van desde 0 a 255            ##*/
/*## dOut --> 8 salidas digitales del sistema cuyos valores van desde 0 a 255            ##*/
/*##                                                                                     ##*/
/*## Esta estructura de frame se pretende usar en un micro bluepill el cual enviara toda ##*/
/*## la informacion, pero de momento se realiza una simulacion enviando frame con        ##*/
/*## valores aleatorios con un archivo en C.                                             ##*/
/*## Año: 2023                                                                           ##*/
/*## Curso: 5R1                                                                          ##*/
/*## Catedra: Técnicas Digitales III                                                     ##*/
/*## Autores: Juarez Daniel, Torres Heber, Sosa Nahuel                                   ##*/
/*#########################################################################################*/

#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget widget;
    widget.show();  //Ejecuta el widget

    return a.exec();
}
