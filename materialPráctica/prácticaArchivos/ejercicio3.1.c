#include <stdio.h>

int main() {

    FILE * pA;

    pA = fopen("./texto.txt", "r"); // abrir archivo en modo lectura

    int contador = 0;

    char buffer[100];

    if(pA != NULL) {

        while (fgets(buffer, sizeof(buffer), pA) != NULL) {

            contador++;
        }

        if(fclose(pA)) {
            printf("Error al cerrar el archivo\n");
        }

        printf("El numero de lineas en el archivo es: %d\n", contador);

    } else {
        printf("Error al abrir el archivo\n");
    }


    return 0;
}
