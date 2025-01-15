#include <stdio.h>
#include <string.h>

struct poligono {

    char nombre[20];
    int lados;
    float longitudLados, area;
};

int main() {

    struct poligono p1;

    strcpy(p1.nombre, "Pentagono.");

    p1.lados = 5;
    p1.longitudLados = 7.4;
    p1.area = 35.3;


    printf("Nombre: %s\nLados: %d\nLongitud Lados: %.1f\nArea: %.1f\n", p1.nombre, p1.lados, p1.longitudLados, p1.area);


    return 0;
}
