#include <stdio.h>

int main() {
    FILE *archivo;
    archivo = fopen("datos.txt", "rb"); // Abre el archivo en modo lectura binaria

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
        printf("%02x ", buffer[i]); // Imprime los datos en hexadecimal
    }

    free(buffer); // Libera la memoria del búfer

    return 0;
}