/*#########################################################################################*/
/*##                                 GENERACION DE FRAMES                                ##*/
/*##-------------------------------------------------------------------------------------##*/
/*## En el siguiente script lo que se hace es generar los frame para ser enviados por el ##*/
/*## puerto serie. La estructura de cada frame viene indicada por la cátedra de la       ##*/
/*## siguiente manera: Cabecera + contador + info, donde                                 ##*/
/*## Cabecera --> Valor fijo 0x1b                                                        ##*/
/*## Contador --> Se incrementa con cada frame enviado, se usa para tener un control     ##*/
/*## Info --> La misma contiene valores de entradas y salidas analógicas y digitales     ##*/
/*## Para este ejemplo se almacenara cada frame en archivos .tex y .bin, el cual este    ##*/
/*## último sera el que enviaremos por puerto serie mediante el software "realTerm"      ##*/
/*## luego se realizara la comparación con lo generado con este script y lo almacenado   ##*/
/*## con Qt, la cual debe ser exacta.                                                    ##*/
/*## Autor: Jaurez Daniel, Sosa Nahuel, Torres Heber                                     ##*/
/*## Curso: 5R1                                                                          ##*/
/*## Catedra: Técnicas Digitales III                                                     ##*/
/*## Año: 2023                                                                           ##*/
/*#########################################################################################*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//Declaracion de estructuras y uniones 
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
} frame_t; //fin de struct

typedef union
{
  frame_t tramaEntrada;
  char    tramaEntradaChar[24];
} charFrame_t; //fin de union


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
    printf("Archivos creados. Escribiendo los frames...\n");
    
    tramaIn.start=start;
    
    int k=0;
    int j=0;
    while(k<910)
    {
      tramaIn.count=j;
        
        
      aIn1 = 0 + rand()%4000;
      tramaIn.a1in=aIn1;
        
      aIn2=aIn1+5;
      tramaIn.a2in=aIn2;
        
      aIn3=aIn2+5;
      tramaIn.a3in=aIn3;
        
      aIn4=aIn3+5;
      tramaIn.a4in=aIn4;
        
      aIn5=aIn4+5;
      tramaIn.a5in=aIn5;
        
      aIn6=aIn5+5;
      tramaIn.a6in=aIn6;
        
      aIn7=aIn6+5;
      tramaIn.a7in=aIn7;
        
      aIn8=aIn7+5;
      tramaIn.a8in=aIn8;
     
      
      aOut1 = 0 + rand()%4090;
      tramaIn.a1out=aOut1;
      
      aOut2=aOut1+5;
      tramaIn.a2out=aOut2;
      
      
      dIn = 0 + rand()%255;
      tramaIn.dIns=dIn;
      
      
      dOut = 0 + rand()%255;
      tramaIn.dOuts=dOut;
      
      // ESCRIBE EN ARCHIVO DE TEXTO
      fprintf(ptrArchTxt, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", start, tramaIn.count,
              aIn1,aIn2,aIn3,aIn4,aIn5,aIn6,aIn7,aIn8,aOut1,aOut2,dIn,dOut);
      
      // ESCRIBE EN ARCHIVO BINARIO
      fwrite(&tramaIn, sizeof(frame_t), 1, ptrArchBin);
      
      k++;
      j++;
      if(j>255)
        j=0;
    }
    
    fclose(ptrArchTxt);
    fclose(ptrArchBin);
  }

  return 0;
}

