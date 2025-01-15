#include <stdio.h>
#include <string.h>

struct carta {

    int numero;
    char palo[20];
};

int main() {

    struct carta c1;

    c1.numero = 6;

    strcpy(c1.palo, "basto");

    printf("Numero: %d\nPalo: %s\n", c1.numero, c1.palo);



    return 0;
}
