#include <stdio.h>

int main() {

    int i, j;

    int alumno = 0;
    int promedio = 0;
    int sumaNotas = 0;

    int matriz[4][4] =
    {
        10, 9, 8, 7,
        5,  4, 3, 6,
        6,  5, 7, 8,
        6,  8, 6, 5

    };



    for (i=0; i<4; i++) {       // FILAS

        promedio = 0;
        sumaNotas = 0;

        for (j=0; j<4; j++) {   // COLUMNAS

            sumaNotas += matriz[i][j];

            printf(" %d", matriz[i][j]);
        }

        promedio = sumaNotas / 4;

        printf(" Promedio: %d\n", promedio);

        printf("\n");
    }


    printf("\n");


    for (i=0; i<4; i++) {

        alumno++;
        printf("Alumno: %d \n", alumno);
    }



    return 0;
}
