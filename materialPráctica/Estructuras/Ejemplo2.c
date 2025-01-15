#include <stdio.h>
#include <string.h>

struct libro {

    char titulo[50];
    char autor[30];
    char editorial[30];
    int anio;

};

int main() {

    struct libro l1;

    strcpy(l1.titulo, "El Duelo.");
    strcpy(l1.autor, "Gabriel Rolon.");
    strcpy(l1.editorial, "Planeta.");

    l1.anio = 2020;


    printf("Titulo: %s\nAutor: %s\nEditorial: %s\nAnio: %d\n", l1.titulo, l1.autor, l1.editorial, l1.anio);



    return 0;
}
