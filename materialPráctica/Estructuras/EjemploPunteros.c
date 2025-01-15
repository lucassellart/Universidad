#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct alummnoo {

    int matricula;
    char nombre[20], carrera[40], direccion[20];
    float promedio;
};

int main() {

    struct alummnoo *al1;       // Declaro un puntero a una estructura

    al1 = (struct alummnoo*) malloc(sizeof(struct alummnoo));       // Acá estoy creando el malloc

    //(*al1).matricula = 714;     // Accedo a la estructura mediante puntero

    al1->matricula = 801;

    strcpy(al1->nombre, "BETURRI");

    strcpy(al1->carrera, "Analista Universitario en Sistemas");

    strcpy(al1->direccion, "Av.Obelisco 277");

    al1->promedio = 8.4;

    printf("Matricula: %d\nNombre: %s\nCarrera: %s\nDireccion: %s\nPromedio: %.2f\n", al1->matricula, al1->nombre, al1->carrera, al1->direccion, al1->promedio);


    return 0;
}
