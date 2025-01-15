#include <stdio.h>

int main() {

    int i = 5;
    int j[] = {1,28,444,0,5,6,716,8,99,10};

    char x = 'a', pal[] = "texto en c";

    int *pi;
    char *pc;

    pi = &i;

    // DESARROLLO:

    //printf("(1) Por variable: \ tdir.&i: %p \ tvalor: %d\n", &i, i);

    //printf("\n(2) Por puntero: tdir.pi: %p \ tvalor: %d\n ", pi, *pi);



    /*
    printf("\n(3)");

    for (int a=0; a<10; a++) {

        //printf("\n%d\n", j[a]);

        printf(" tdir.&j[a]: %p \ tvalor: %d\n ", &j[a], j[a]);
    }

    printf("\n");

    */


    /*
    for (int b=0; b<10; b++) {

        pi = &j[b];

        printf(" tdir.&j[b]: %p \ tvalor: %d\n", pi, *pi);
    }
    */


    // Recorrer el vector con algebra de punteros:



    /*
    pi = j;

    for (int b=0; b<10; b++) {

        printf(" Direccion memoria: %p \ Valor: %d\n", pi + b, *(pi + b));
    }

    */


    // 5:

    printf(" Direccion: %p \ Valor: %c\n ", &x, x);

    printf("\n");
    int k=0;
    while (pal[k] != '\0') {

        printf(" Direccion: %p \ Valor: %c\n", &pal[k], pal[k]);

        k++;
    }


    pc = &x;

    printf("\n");
    printf(" Direccion: %p \ Valor: %c\n", pc, *pc);


    // 6:


    printf("\n");

    printf(" Direccion pi: %p\n ", pi);
    printf("Direccion pc: %p ", pc);






    return 0;
}
