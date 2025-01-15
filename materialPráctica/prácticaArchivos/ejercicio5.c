#include <stdio.h>

int main() {

    FILE * origen, * copia;

    int caracter;

    // abrir el archivo origen en modo lectura
    origen = fopen("./origen.txt", "r");

    if (origen == NULL) {   // verificar si el archivo se abre correctamente
        printf("Error al abrir el archivo origen.\n");
        return 1;
    }

    // abrir el archivo copia en modo escritura
    copia = fopen("./copia.txt", "w");

    if (copia == NULL) {
        printf("Error al abrir el archivo copia.\n");
        return 1;
    }

    // copiar caracter por caracter desde origen a copia
    while ((caracter = fgetc(origen)) != EOF) {
        fputc(caracter, copia);
    }

    // cerrar ambos archivos después de realizar la copia

    if (fclose(origen) != 0) {
        printf("Error al cerrar el archivo origen.\n");
    }

    if (fclose(copia) != 0) {
        printf("Error al cerrar el archivo copia.\n");
    }


    return 0;
}
