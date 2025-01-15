#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    int r, c, i, j = 0;

    printf("Ingrese el numero de renglones: ");
    scanf("%d", &r);

    printf("\nIngrese el numero de columnas: ");
    scanf("%d", &c);

    int matriz[r][c];

    srand(time(NULL));

    printf("\nMATRIZ ORIGINAL: \n");

    for (i=0; i<r; i++) {               // fila

        for (j=0; j<c; j++) {           // columna

            matriz[i][j] = rand() % 9 + 1;

            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMATRIZ TRANSPUESTA: \n");

    for (i=0; i<c; i++) {               // fila

        for (j=0; j<r; j++) {           // columna

            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }



    return 0;
}
