#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i, j, N = 0;


    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d", &N);

    int matrizUno[N][N];
    int matrizDos[N][N];
    int matrizSuma[N][N];

    printf("\nContenido de las matrices: \n");
    printf("\nMatriz 1: \n");

    srand(time(NULL));

    for (i=0; i<N; i++) {

        for (j=0; j<N; j++) {

            matrizUno[i][j] = rand() % 9 + 1;

            printf("%d ", matrizUno[i][j]);
        }
        printf("\n");
    }


    printf("\nMatriz 2: \n");

    for (i=0; i<N; i++) {

        for (j=0; j<N; j++) {

            matrizDos[i][j] = rand() % 9 + 1;

            printf("%d ", matrizDos[i][j]);
        }
        printf("\n");
    }


    printf("\nSuma: \n");


    for (i=0; i<N; i++) {

        for (j=0; j<N; j++) {

            matrizSuma[i][j] = matrizUno[i][j] + matrizDos[i][j];

            printf("%d ", matrizSuma[i][j]);
        }
        printf("\n");
    }




    return 0;
}
