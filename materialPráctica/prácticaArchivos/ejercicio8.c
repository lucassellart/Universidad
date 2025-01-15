#include <stdio.h>
#include <string.h>

#define MAX_PALABRAS 50

int main() {

    FILE * archivoEntrada, * archivoSalida;

    char palabras[MAX_PALABRAS];
    char caracter;

    int i = 0;  // índice que indica la posición actual en el array palabras[]

    archivoEntrada = fopen("./documento.txt", "r");

    if (archivoEntrada != NULL) {

        while ((caracter = fgetc(archivoEntrada)) != EOF) {

            if ((caracter >= 'a' && caracter <= 'z') ||
            (caracter >= 'A' && caracter <= 'Z')) {

                palabras[i++] = caracter;

            } else {
                // si encuentro un espacio, salto de linea o otro:

                if (i > 0) {
                    palabras[i] = '\0';
                }
            }
        }

    } else {
        printf("Error al abrir el archivo.\n");
    }

    fclose(archivoEntrada);

    archivoSalida = fopen("./documento_modificado.txt", "w");

    if (archivoSalida != NULL) {



    } else {
        printf("Error al abrir el archivo.\n");
    }

    return 0;
}
