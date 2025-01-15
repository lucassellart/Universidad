#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char nombre[50];
    int edad;
    float promedio;

} Estudiante;

void ingresarEstudiante(Estudiante * estud);

void mostrarEstudiante(Estudiante e);

void guardarEstudiantes(Estudiante estds[], int n);

void buscarEstudiantePorNombre(const char * nomb);

void actualizarPromedio(const char * nmb, float prom);

int main() {

    Estudiante est[5];      // Array de estudiantes (5 estudiantes con nombre, edad y promedio)

    for(int i=0; i<5; i++) {

       ingresarEstudiante(&(est[i]));
    }

    guardarEstudiantes(est, 5);

    char nombre_a_buscar[50];
    float nuevoPromedio = 0.0;

    printf("\nIngrese nombre a buscar: \n");
    scanf("%s", nombre_a_buscar);

    buscarEstudiantePorNombre(nombre_a_buscar);

    printf("\nIngrese nombre de estudiante: \n");
    scanf("%s", nombre_a_buscar);
    printf("Ingrese nuevo promedio: \n");
    scanf("%f", &nuevoPromedio);    // Me faltó poner le '&', necesito guardar el nuevo promedio en la direccion de memoria

    actualizarPromedio(nombre_a_buscar, nuevoPromedio);

    buscarEstudiantePorNombre(nombre_a_buscar);

    return 0;
}

void ingresarEstudiante(Estudiante * estud) {

    printf("Ingrese el nombre del estudiante: \n");
    scanf("%s", estud->nombre);
    printf("Ingrese la edad: \n");
    scanf("%d", &estud->edad);        // por qué hay que escribir el &? por qué es necesaria la direc. de memoria?
    printf("Ingrese el promedio: \n");
    scanf("%f", &estud->promedio);  // por qué hay que escribir el &? por qué es necesaria la direc. de memoria?
}

void mostrarEstudiante(Estudiante e) {

    printf("Nombre: %s\n", e.nombre);
    printf("Edad: %d\n", e.edad);
    printf("Promedio: %.2f \n", e.promedio);
}

void guardarEstudiantes(Estudiante estds[], int n) {

    FILE * pArchivo;

    pArchivo = fopen("./estudiantes.dat", "wb+");    // Corrección: el modo de apertura correcto sería: "wb+" porque permite lectura y escritura
                                                    // "wb" permite solo escritura del archivo
    if (pArchivo != NULL) {

        fwrite(estds, sizeof(Estudiante), n, pArchivo);

    } else {
        printf("Error al abrir el archivo.");
    }

    fclose(pArchivo);
}

void buscarEstudiantePorNombre(const char * nomb) {

    FILE * pA;

    pA = fopen("./estudiantes.dat", "rb");

    Estudiante est;         // Necesito un espacio en memoria donde almacenar temporalmente los datos que leo del archivo

    int encontrado = 0;     // Bandera para saber si encontramos al estudiante

    if (pA != NULL) {

        // Leer registros uno por uno:

        while(fread(&est, sizeof(Estudiante), 1, pA) == 1) {

            if (strcmp(est.nombre, nomb) == 0) {
                printf("Estudiante encontrado!\n");
                printf("Nombre: %s\n", est.nombre);
                printf("Edad: %d\n", est.edad);
                printf("Promedio: %.2f\n", est.promedio);

                encontrado = 1;
                break;  // Salimos del bucle porque ya encontramos al estudiante
            }
        }

    } else {
        printf("Error al abrir el archivo.");
    }

    fclose(pA);     // el archivo lo tengo que cerrar al final del ciclo while, cuando termina de leer todos los registros
}

void actualizarPromedio(const char * nmb, float prom) {

    FILE * pARCH;

    pARCH = fopen("./estudiantes.dat", "rb+");

    Estudiante e;
    int encontrado = 0;

    if (pARCH != NULL) {

        while (fread(&e, sizeof(Estudiante), 1, pARCH) == 1) {  // Registro leído correctamente
                                                                // El puntero del archivo avanza al final de ese registro

            if (strcmp(e.nombre, nmb) == 0) {   // Estudiante encontrado

                e.promedio = prom;  // Cambio el valor del promedio en memoria, pero aún no está hecho el cambio en el archivo

                fseek(pARCH, -sizeof(Estudiante), SEEK_CUR);    // Mueve el puntero al comienzo del registro p/ sobreescribir con los datos modificados
                fwrite(&e, sizeof(Estudiante), 1, pARCH);       // Escribe el registro modificado con el nuevo promedio

                encontrado = 1;
                break;
            }
        }

    } else {
        printf("Error al abrir el archivo.");
    }

    fclose(pARCH);
}

