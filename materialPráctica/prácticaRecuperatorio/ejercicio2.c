#include <stdio.h>

int main() {

    FILE * pa;

    char nombre[100];
    char apellido[100];

    pa = fopen("./datos.txt", "r");

    if (pa != NULL) {   // La lectura del archivo puede ser letra por letra o cadenas completas

        fscanf(pa, "%s %s", nombre, apellido);

        while (!feof(pa)) {

            printf("Nombre leido: %s, Apellido leido: %s\n", nombre, apellido);
            fscanf(pa, "%s %s", nombre, apellido);
        }

        fclose(pa);

    } else {
        printf("Error al abrir el archivo.");
    }




    return 0;
}
