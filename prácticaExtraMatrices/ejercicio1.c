#include <stdio.h>

int main() {

    int N;
    int matriz[N][N];

    printf("Ingrese el tamanio de la matriz por favor: ");
    scanf("%d", &N);

    for(int i=0; i<N; i++) {        // ciclo para recorrer filas

        for(int j=0; j<N; j++) {    // ciclo para recorrer columnas

            if (i == j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

    for (int i=0; i<N; i++) {       // ciclo para mostrar la matriz

        for (int j=0; j<N; j++) {

            printf("Matriz %d\n: ", matriz[i][j]);
        }
    }

    return 0;
}