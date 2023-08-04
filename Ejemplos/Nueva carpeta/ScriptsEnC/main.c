#include <stdio.h>

int main() {
    FILE *archivo;
    archivo = fopen("datos.txt", "wb"); // Abre el archivo en modo escritura binaria

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    unsigned char contador = 0;
    unsigned char info[22] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
                              0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15};

    for (int i = 0; i < 40; i++) { // Cambia este valor para controlar cuántas tramas se generan
        // Escribe la trama en el archivo
        fwrite("\x1b", 1, 1, archivo); // 0x1b
        fwrite(&contador, 1, 1, archivo);
        fwrite(info, sizeof(info), 1, archivo);

        contador++; // Incrementa el contador
    }

    fclose(archivo); // Cierra el archivo

    printf("Archivo generado exitosamente.\n");

    return 0;
}