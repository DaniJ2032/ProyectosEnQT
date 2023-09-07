#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*#########################################################################################*/
/*##                        DECLARACIÓN DE ESTRUCTURAS Y UNIONES                         ##*/
/*#########################################################################################*/

typedef struct {
  // Byte de caebcera.
  uint8_t start; 
  // Contador.  
  uint8_t count; 
  // 8 entradas analógicas (12 bits).
  uint16_t inA1; 
  uint16_t inA2;
  uint16_t inA3;
  uint16_t inA4;
  uint16_t inA5;
  uint16_t inA6;
  uint16_t inA7;
  uint16_t inA8;
  // 2 salidas analógicas.
  uint16_t outA1; 
  uint16_t outA2;
  // 8 entradas digitales.
  uint8_t insDig;  
  // 8 salidas digitales.
  uint8_t outsDig; 

} frame_t; //Fin de struct

typedef union
{
  frame_t frameEntrada;
  char    frameEntradaChar[24];
} charFrame_t; //Fin de union

//main principal
int main( int argc, char *argv[])
{
  uint8_t start=0x1b; //Cabecera, siempre de valor fijo.
  uint16_t aIn1,aIn2,aIn3,aIn4,aIn5,aIn6,aIn7,aIn8; // 8 entradas analógicas.
  uint16_t aOut1,aOut2; // 2 salidas analógicas.
  uint8_t dIn;          // 8 entradas digitales.
  uint8_t dOut;         // 8 salidas digitales.
  frame_t tramaIn={0,0,0,0,0,0,0,0,0,0,0,0,0,0};  

  FILE *ptrArchTxt; // Puntero para los archivos
  FILE *ptrArchBin;

  // Imprime los tamaños de los nuevos tipos de datos.
  printf("\nTamaño de frame_t: %ld / tamaño de charFrame_t: %ld\n",sizeof(frame_t),sizeof(charFrame_t));

  //generacion de los archivos .txt y .bin 
  if( (ptrArchTxt=fopen("archivoComSerial.txt", "w"))==NULL || ((ptrArchBin=fopen("archivoComSerial.bin","wb"))==NULL) )
    printf("Error al abrir los archivos.\n");
  else
  {
    printf("Archivos creados. Escribiendo tramas...\n");
    
    tramaIn.start = start;

    //Se generan 910 frame para obtener un archivo de 1 Mega
    for (int k = 0, j = 0; k < 910; k++, j++) {
        tramaIn.count = j;
        // genera valores rand para las entradas y salidas analog.
        //se almacena cada valor random en cada variable  
        for (int i = 0, aIn = 0; i < 8; i++) {
            unsigned short aIn1 = 0 + rand() % 4095;
            switch (i) {
                case 0: tramaIn.inA1 = aIn1; break;
                case 1: tramaIn.inA2 = aIn1; break;
                case 2: tramaIn.inA3 = aIn1; break;
                case 3: tramaIn.inA4 = aIn1; break;
                case 4: tramaIn.inA5 = aIn1; break;
                case 5: tramaIn.inA6 = aIn1; break;
                case 6: tramaIn.inA7 = aIn1; break;
                case 7: tramaIn.inA8 = aIn1; break;
            }
        }
        for (int i = 0, aOut = 0; i < 2; i++) {
            unsigned short aOut1 = 0 + rand() % 4095;
            switch (i) {
                case 0: tramaIn.outA1 = aOut1; break;
                case 1: tramaIn.outA2 = aOut1; break;
            }
        }
        //generacion de rand para las saldias y entradas digitales.
        tramaIn.insDig = 0 + rand() % 255;
        tramaIn.outsDig = 0 + rand() % 255;

        //Armamos los frame y se los escribe en un archivo .txt
        fprintf(ptrArchTxt, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", start, tramaIn.count,
                tramaIn.inA1, tramaIn.inA2, tramaIn.inA3, tramaIn.inA4, tramaIn.inA5, tramaIn.inA6, tramaIn.inA7, tramaIn.inA8,
                tramaIn.outA1, tramaIn.outA2, tramaIn.insDig, tramaIn.outsDig);

        //Armamos los frame y se los escribe en un archivo .bin
        fwrite(&tramaIn, sizeof(frame_t), 1, ptrArchBin);

        if (j > 255)  //reset del contador
            j = 0;
    }
    //Cierre de los  punteros para los archivos.
    fclose(ptrArchTxt);
    fclose(ptrArchBin);
  }
  
  return 0;
} //fin de main.

