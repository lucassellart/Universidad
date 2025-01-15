#include <stdio.h>

struct libro {

    char titulo[30], autor[20], editorial[30];
    int anio, edicion;
};

int main() {

    struct libro lib1 = {"El Quijote.", "Cervantes.", "Limusa.", 1987, 4}, lib2;

    lib2 = lib1;


    printf("Titulo: %s\nAutor: %s\nEditorial: %s\nAnio: %d\nEdicion: %d\n", lib2.titulo, lib2.autor, lib2.editorial, lib2.anio, lib2.edicion);


    return 0;
}
