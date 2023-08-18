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

#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE puerto_serie;
    const char *nombre_puerto = "COM2"; // Cambia el nombre del puerto según corresponda
    unsigned char contador = 0;
    unsigned char info[22] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
                              0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15};

    // Abre el puerto serie
    puerto_serie = CreateFile(nombre_puerto, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (puerto_serie == INVALID_HANDLE_VALUE) {
        printf("Error al abrir el puerto serie.\n");
        return 1;
    }

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(puerto_serie, &dcbSerialParams)) {
        printf("Error al obtener la configuración del puerto serie.\n");
        CloseHandle(puerto_serie);
        return 1;
    }

    dcbSerialParams.BaudRate = CBR_9600; // Velocidad del puerto serie (9600 bps)
    dcbSerialParams.ByteSize = 8;        // Tamaño de byte
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(puerto_serie, &dcbSerialParams)) {
        printf("Error al configurar el puerto serie.\n");
        CloseHandle(puerto_serie);
        return 1;
    }

    // for (int i = 0; i < 10; i++) { // Cambia este valor para controlar cuántas tramas se envían
    //     }

    while(1){    
        unsigned char trama[24];
        trama[0] = 0x1b;
        trama[1] = contador;
        memcpy(&trama[2], info, sizeof(info));

        DWORD bytesEscritos;
        if (!WriteFile(puerto_serie, trama, sizeof(trama), &bytesEscritos, NULL)) {
            printf("Error al escribir en el puerto serie.\n");
            CloseHandle(puerto_serie);
            return 1;
        }

        contador++; // Incrementa el contador
        Sleep(100); // Espera 1 segundo antes de enviar la siguiente trama
        printf("Trama enviada \n");
    }

    CloseHandle(puerto_serie); // Cierra el puerto serie

    printf("Tramas enviadas exitosamente.\n");

    return 0;
}


