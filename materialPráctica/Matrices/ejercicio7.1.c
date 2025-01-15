#include <stdio.h>

int main() {

    int i, n = 0;
    int v[10], *p;

    printf("Ingrese los valores del vector: \n");

    p = &v[0];// es equivalente a p = v;

    for(i=0; i<10; i++) {

        scanf("%d", p+i);

    }


    printf("\nVector a la inversa: \n");

    for(i=9 ; i >= 0 ; i--) {

        printf("%d\n", *(p+i));
    }



    return 0;
}

