#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i, j;
    int N = 0;

    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d", &N);

    printf("Contenido de las matrices: \n");

    printf("Matriz 1: \n");

    int matriz[N][N];

    srand(time(NULL));                          // Genera números aleatorios diferentes cada vez que se ejecuta el programa

    for (i=0; i<N; i++) {

        for (j=0; j<N; j++) {

            matriz[i][j] = rand() % 9 + 1;      // Genera números aleatorios entre 1 y 9 y los guarda en la matriz

            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }






    return 0;
}
