#include <stdio.h>
#include <string.h>

struct alumno{

    int matricula;
    char nombre[20];
    char carrera[40];
    float promedio;
    char direccion[20];
};

int main() {

    struct alumno a1;

    a1.matricula = 1607;

    strcpy(a1.nombre, "Lucas.");
    strcpy(a1.carrera, "Analista Universitario en Sistemas.");

    a1.promedio = 8.4;

    strcpy(a1.direccion, "Av.Obelisco 623.");


    printf("Matricula: %d\nNombre: %s\nCarrera: %s\nPromedio: %.1f\nDireccion: %s\n", a1.matricula, a1.nombre, a1.carrera, a1.promedio, a1.direccion);


    return 0;
}
