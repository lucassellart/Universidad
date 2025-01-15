#include <stdio.h>

int main() {

    FILE * pArchivo;

    pArchivo = fopen("./saludo.txt", "a");

    if (pArchivo != NULL) {

        fputs("\nHola, Mundo!\n", pArchivo);

        if (fclose(pArchivo)) {

            printf("Error al cerrar el archivo.\n");
        }
    } else {

        printf("Error al abrir el archivo.\n");
    }


    return 0;
}
