#include <stdio.h>

int main() {

    int tam = 0;
    int i, j;

    printf("Ingrese el tamanio de la matriz: ");
    scanf("%d", &tam);

    int matriz[tam][tam];

    for (i=0; i<tam; i++) {         // el i es el indice para las filas

        for (j=0; j<tam; j++) {     // el j es el indice para las columnas

            if (i == j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

    printf("\n");

    for (i=0; i<tam; i++) {

        for (j=0; j<tam; j++) {

            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


    return 0;
}
