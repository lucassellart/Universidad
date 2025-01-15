#include <stdio.h>


int main() {

    FILE * pArchivo;

    pArchivo = fopen("./texto.txt", "r");

    int contador = 0;

    char buffer[100];   // cadena de caracteres que almacena una linea completa leida del archivo

    if (pArchivo != NULL) {

        fgets(buffer, sizeof(buffer), pArchivo) {   //  REVISAR


        }

    } else {
        printf("Error al abrir el archivo.\n");
    }


    return 0;
}
