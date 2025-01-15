#include <stdio.h>

int main() {

    int i, j;
    int alumnos, promedio = 0;

    int sumaNotas[4];
    int sumaAsignaturas[4];

    int matriz[4][4] =
    {
        8, 8, 8, 8,
        6, 6, 6, 6,
        4, 4, 4, 4,
        7, 4, 1, 6
    };


    for (i=0; i<4; i++) {

        alumnos++;

        sumaNotas[i] = 0;

        for (j=0; j<4; j++) {

            sumaNotas[i] += matriz[i][j];

            printf("%d ", matriz[i][j]);
        }

        printf(" Alumno %d: ", alumnos);

        promedio = sumaNotas[i] / 4;
        printf(" El promedio es: %d", promedio);


        if (promedio >= 8 && promedio <= 10) {
            printf(" -> PROMOVIDO!");

        } else if (promedio < 8 && promedio >= 6) {
            printf(" -> REGULAR!");

        } else {
            printf(" -> LIBRE!");
        }


        printf("\n");
    }

    printf("\n");

    for (i=0; i<4; i++) {

        sumaAsignaturas[i] = 0;

        for (j=0; j<4; j++) {

            sumaAsignaturas[i] += matriz[j][i];

            //printf("%d ", matriz[j][i]);
        }

        int promAsignaturas = 0;
        promAsignaturas = sumaAsignaturas[i] / 4;

        printf("%d ", promAsignaturas);

    }

    printf(" -> Promedio asignaturas\n");


    return 0;
}
