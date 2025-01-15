#include <stdio.h>
#include <string.h>

struct direc{

    char calle[20], tipoVivienda[20];
    int num, cp;
};

struct direc dameDirec();

int main() {

    struct direc d2;

    d2 = dameDirec();

    printf("Calle: %s\nNumero: %d\nCodigo Postal: %d\nTipo: %s\n", d2.calle, d2.num, d2.cp, d2.tipoVivienda);


    return 0;
}

struct direc dameDirec() {

    struct direc d1;

    strcpy(d1.calle, "Galvez.");
    d1.num = 892;
    d1.cp = 2000;
    strcpy(d1.tipoVivienda, "Casa.");

    return d1;
};
