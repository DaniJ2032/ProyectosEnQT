#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*#########################################################################################*/
/*##                        DECLARACIÓN DE ESTRUCTURAS Y UNIONES                         ##*/
/*#########################################################################################*/

typedef struct
{
  uint8_t start; // Byte de inicio.

  uint8_t count; // Contador.

  uint16_t a1in; // 8 entradas analógicas (12 bits).
  uint16_t a2in;
  uint16_t a3in;
  uint16_t a4in;
  uint16_t a5in;
  uint16_t a6in;
  uint16_t a7in;
  uint16_t a8in;

  uint16_t a1out; // 2 salidas analógicas.
  uint16_t a2out;

  uint8_t dIns;  // 8 entradas digitales.
  
  uint8_t dOuts; // 8 salidas digitales.

} frame_t;

/*******************************************************************************************/

typedef union
{
  frame_t tramaEntrada;
  char    tramaEntradaChar[24];
} charFrame_t;


/*#########################################################################################*/
/*##                                    PROGRAMA PRINCIPAL                               ##*/
/*#########################################################################################*/

int main( int argc, char *argv[])
{
  uint8_t start=0x1b;
  uint16_t aIn1,aIn2,aIn3,aIn4,aIn5,aIn6,aIn7,aIn8;
  uint16_t aOut1,aOut2; // 2 salidas analógicas.
  uint8_t dIn;         // 2 salidas analógicas.
  uint8_t dOut;        // 2 salidas analógicas.
  frame_t tramaIn={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  FILE *ptrArchTxt;
  FILE *ptrArchBin;

  // Imprime los tamaños de los 'nuevos tipos de datos'.
  printf("\nTamaño de frame_t: %ld / tamaño de charFrame_t: %ld\n",sizeof(frame_t),sizeof(charFrame_t));

  if( (ptrArchTxt=fopen("archivoComSerial.txt", "w"))==NULL || ((ptrArchBin=fopen("archivoComSerial.bin","wb"))==NULL) )
    printf("Los archivos no pudieron abrirse.\n");
  else
  {
    printf("Archivos creados. Escribiendo tramas...\n");
    
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

