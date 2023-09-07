// #include <stdio.h>

// int main() {
//     FILE *archivo;
//     archivo = fopen("datos.bin", "wb"); // Abre el archivo en modo escritura binaria

//     if (archivo == NULL) {
//         printf("No se pudo abrir el archivo.\n");
//         return 1;
//     }

//     unsigned char contador = 0;
//     unsigned char info[22] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
//                               0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15};

//     for (int i = 0; i < 40; i++) { // Cambia este valor para controlar cuántas tramas se generan
//         // Escribe la trama en el archivo
//         fwrite("\x1b", 1, 1, archivo); // 0x1b
//         fwrite(&contador, 1, 1, archivo);
//         fwrite(info, sizeof(info), 1, archivo);

//         contador++; // Incrementa el contador
//     }

//     fclose(archivo); // Cierra el archivo

//     printf("Archivo generado exitosamente.\n");

//     return 0;
// }

// #include <stdio.h>

// int main() {
//     FILE *archivo;
//     archivo = fopen("datos.bin", "wb"); // Abre el archivo en modo escritura

//     if (archivo == NULL) {
//         printf("No se pudo abrir el archivo.\n");
//         return 1;
//     }

//     unsigned char contador = 0;
//     unsigned char info[22] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
//                               0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15};

//     for (int i = 0; i < 40; i++) { // Cambia este valor para controlar cuántas tramas se generan
//         fprintf(archivo, "0x1b%02x", contador); // Escribe el valor del contador en hexadecimal

//         for (int j = 0; j < sizeof(info); j++) {
//             fprintf(archivo, "%02x", info[j]); // Escribe los valores de info en hexadecimal
//         }

//         // fprintf(archivo, "\n");

//         contador++; // Incrementa el contador
//     }

//     fclose(archivo); // Cierra el archivo

//     printf("Archivo generado exitosamente.\n");

//     return 0;
// }

// 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FRAMES 910 // Cambia este valor para controlar cuántos frames se generan

int main() {
    srand(time(NULL)); // Inicializa la semilla del generador de números aleatorios

    FILE *archivo_txt, *archivo_bin;
    archivo_txt = fopen("datos.txt", "w"); // Abre el archivo en modo escritura
    archivo_bin = fopen("datos.bin", "wb"); // Abre el archivo binario en modo escritura

    if (archivo_txt == NULL || archivo_bin == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    for (int frame = 0; frame < NUM_FRAMES; frame++) {
        // Genera valores aleatorios para las entradas/salidas analógicas y digitales
        unsigned char contador = frame;
        unsigned short entradas_analogicas[8];
        unsigned short salidas_analogicas[2];
        unsigned char entradas_digitales;
        unsigned char salidas_digitales;

        for (int i = 0; i < 8; i++) {
            entradas_analogicas[i] = rand() % 4097;
        }

        for (int i = 0; i < 2; i++) {
            salidas_analogicas[i] = rand() % 4097;
        }

        entradas_digitales = rand() % 256;
        salidas_digitales = rand() % 256;

        // Escribe los datos en el archivo .txt
        fprintf(archivo_txt, "0x1b%02x", contador);
        for (int i = 0; i < 8; i++) {
            fprintf(archivo_txt, "%04x", entradas_analogicas[i]);
        }
        for (int i = 0; i < 2; i++) {
            fprintf(archivo_txt, "%04x", salidas_analogicas[i]);
        }
        fprintf(archivo_txt, "%02x%02x\n", entradas_digitales, salidas_digitales);

        // Escribe los datos en el archivo .bin
        fwrite("\x1b", 1, 1, archivo_bin);
        fwrite(&contador, 1, 1, archivo_bin);
        fwrite(entradas_analogicas, sizeof(entradas_analogicas), 1, archivo_bin);
        fwrite(salidas_analogicas, sizeof(salidas_analogicas), 1, archivo_bin);
        fwrite(&entradas_digitales, 1, 1, archivo_bin);
        fwrite(&salidas_digitales, 1, 1, archivo_bin);
    }

    fclose(archivo_txt); // Cierra el archivo .txt
    fclose(archivo_bin); // Cierra el archivo .bin

    printf("Archivos generados exitosamente.\n");

    return 0;
}


