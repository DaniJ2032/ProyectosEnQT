#include <stdio.h>

int main() {
    FILE *archivo;
    archivo = fopen("archivoComSerial.bin", "rb"); // Abre el archivo en modo lectura binaria
    int  num = 0;
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    fseek(archivo, 0, SEEK_END); // Mueve el puntero al final del archivo
    long archivo_tamano = ftell(archivo); // Obtiene el tamaño del archivo
    rewind(archivo); // Vuelve el puntero al principio del archivo

    unsigned char *buffer = (unsigned char *)malloc(archivo_tamano); // Crea un búfer para almacenar los datos

    if (buffer == NULL) {
        printf("Error de memoria.\n");
        return 1;
    }

    fread(buffer, archivo_tamano, 1, archivo); // Lee los datos del archivo al búfer
    fclose(archivo); // Cierra el archivo

    for (long i = 0; i < archivo_tamano; i++) {

        num = num+1;
        if (num>24){
            printf("\n");
            num = 0;
        }
        printf("%02x ",buffer[i]); // Imprime los datos en hexadecimal
    }

    free(buffer); // Libera la memoria del búfer

    return 0;
}