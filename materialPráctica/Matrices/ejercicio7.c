#include <stdio.h>

int main() {

    int i, n = 0;

    int numeros[10];
    int *p;                 // puntero para recorrer el array y mostrar sus valores.

    p = numeros;            // esto quiere decir que el puntero va a apuntar a la primer posición del vector



    printf("Ingrese los numeros del vector: \n");

    for (i=0; i<10; i++) {

        p++
    }


    printf("\nNumeros del vector: \n");

    for (i=0; i<10; i++) {

        printf("%d\n", *p++);
    }








    return 0;
}
