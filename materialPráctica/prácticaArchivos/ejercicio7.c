#include <stdio.h>
#include <string.h>

#define MAX_NOMBRES 50     // máximo número de nombres
#define MAX_LONGITUD 50     // máxima longitud de cada nombre

int main() {

    FILE * archivoEntrada, * archivoSalida;

    char nombres[MAX_NOMBRES][MAX_LONGITUD];    // array que almacena varias cadenas de caracteres. Este es mi array de strings.

    int totalNombres = 0;   // cuenta la cant. de nombres leídos en el archivo

    archivoEntrada = fopen("./nombres.txt", "r");

    if (archivoEntrada != NULL) {

        while (fgets(nombres[totalNombres], MAX_LONGITUD, archivoEntrada) != NULL) {

            // sacar el salto de linea al final de cada nombre (si existe)
            nombres[totalNombres][strcspn(nombres[totalNombres], "\n")] = '\0';

            totalNombres++;

            // verificar que no exceda el limite
            if (totalNombres >= MAX_NOMBRES) {
                printf("Se alcanzo el limite maximo de nombres (%d)\n", MAX_NOMBRES);
                break;
            }
        }

    } else {
        printf("Error al abrir el archivo.\n");
    }

    // cerrar el archivo de entrada:

    fclose(archivoEntrada);

    // ordenar los nombres usando el método burbuja:

    for (int i=0; i < totalNombres - 1; i++) {

        for (int j=0; j < totalNombres - i - 1; j++) {

            if (strcmp(nombres[j], nombres[j+1]) > 0) {

                char temporal[MAX_LONGITUD];

                strcpy(temporal, nombres[j]);
                strcpy(nombres[j], nombres[j+1]);
                strcpy(nombres[j+1], temporal);
            }
        }
    }

    // abrir archivo de salida para la escritura:


    archivoSalida = fopen("./nombres_ordenados.txt", "w");

    if (archivoSalida != NULL) {

        // escribir los nombres ordenados:

        for (int i=0; i<totalNombres; i++) {
            fprintf(archivoSalida, "%s\n", nombres[i]);
        }

    } else {
        printf("Error al abrir el archivo.\n");
    }


    fclose(archivoSalida);


    return 0;
}
