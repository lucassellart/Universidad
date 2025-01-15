#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nombre[50];
    int edad;
    float promedio;

} Estudiante;

void ingresarEstudiante(Estudiante * est);
void mostrarEstudiante(Estudiante e);

void guardarEstudiantes(Estudiante estud[], int n);

void buscarEstudiantePorNombre(const char * nom);

void actualizarPromedio(const char * nomb, float promedio);

int main() {

    Estudiante estu[5];     // Array de estructuras (voy a tener 5 estudiantes)

    for(int i=0; i<5; i++) {
        ingresarEstudiante(&(estu[i]));
    }

    /*
    for(int x=0; x<5; x++) {
        mostrarEstudiante(estu[x]);
    }
    */

    guardarEstudiantes(estu, 5);

    char nombre_a_buscar[50];
    float nuevoPromedio = 0.0;

    printf("\nIngrese nombre a buscar: \n");
    scanf("%s", nombre_a_buscar);

    buscarEstudiantePorNombre(nombre_a_buscar);


    printf("Ingrese nombre del estudiante: \n");
    scanf("%s", nombre_a_buscar);
    printf("Ingrese nuevo promedio: \n");
    scanf("%f", &nuevoPromedio);

    actualizarPromedio(nombre_a_buscar, nuevoPromedio);

    buscarEstudiantePorNombre(nombre_a_buscar);


    return 0;
}

void ingresarEstudiante(Estudiante * est) {

    printf("Ingrese el nombre: \n");
    scanf("%s", est->nombre);
    printf("Ingrese la edad: \n");
    scanf("%d", &est->edad);
    printf("Ingrese el promedio: \n");
    scanf("%f", &est->promedio);
}

void mostrarEstudiante(Estudiante e) {

    printf("\nNombre: %s\nEdad: %d\nPromedio: %.2f\n", e.nombre, e.edad, e.promedio);
}

void guardarEstudiantes(Estudiante estud[], int n) {

    FILE * archivo;

    archivo = fopen("./estudiantes.dat", "wb+");

    if (archivo != NULL) {

        fwrite(estud, sizeof(Estudiante), n, archivo);  // no hace falta usar '&' en el 1er argumento porque el nombre del array "estud" ya es un puntero al primer elemento del array
        fclose(archivo);

    } else {
        printf("Error al abrir el archivo.\n");
    }
}

void buscarEstudiantePorNombre(const char * nom) {

    FILE * pArchivo;

    pArchivo = fopen("./estudiantes.dat", "rb");

    Estudiante est;         // instancia de la estructura  para acceder al nombre de los estudiantes
    int encontrado = 0;     // bandera para cuando se encuentra a un estudiante por nombre

    if (pArchivo != NULL) {

        while(fread(&est, sizeof(Estudiante), 1, pArchivo) == 1) {   // registro leído correctamente

            if (strcmp(est.nombre, nom) == 0) {     // Estudiante encontrado por el nombre

                printf("Estudiante encontrado!\n");
                printf("Nombre: %s\n", est.nombre);
                printf("Edad: %d\n", est.edad);
                printf("Promedio: %.2f\n", est.promedio);

                encontrado = 1;
                break;      // necesario para salir del condicional
            }
        }
        fclose(pArchivo);

    } else {
        printf("Error al abrir el archivo.\n");
    }


}

void actualizarPromedio(const char * nomb, float promedio) {

    FILE * parch;

    parch = fopen("./estudiantes.dat", "rb+");

    Estudiante es;
    int encontrado = 0;

    if (parch != NULL) {

        while(fread(&es, sizeof(Estudiante), 1, parch) == 1) {      // registro leído correctamente

            if (strcmp(es.nombre, nomb) == 0) {                     // Los nombres son =

                es.promedio = promedio;                             // actualizo el promedio del estudiante en memoria (falta actualizarlo en el archivo)

                fseek(parch, -sizeof(Estudiante), SEEK_CUR);        // muevo el puntero al comienzo del archivo

                fwrite(&es, sizeof(Estudiante), 1, parch);          // escribo en el archivo con los datos del promedio modificados

                encontrado = 1;
                break;      // para salir del condicional
            }
        }
        fclose(parch);

    } else {
        printf("Error al abrir el archivo.\n");
    }
}

