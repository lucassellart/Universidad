#include <stdio.h>

int main() {

    FILE * pArchivo;

    char nombre[20];
    char apellido[20];

    pArchivo = fopen("./datos.txt", "rt");  // rt: lectura de texto

    if (pArchivo != NULL) {

        fscanf(pArchivo, "%s %s", nombre, apellido);
        while (!feof(pArchivo)) {   // mientras no hayas llegado al final del archivo:

            printf("Nombre leido: %s Apellido leido: %s \n", nombre, apellido);

            fscanf(pArchivo, "%s %s", nombre, apellido);
        }
        if (fclose(pArchivo)) {
            printf("Error al cerrar el archivo.\n");
        }
    } else {
        printf("Error al abrir el archivo.\n");
    }

    return 0;
}
