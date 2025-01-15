#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tiempo{

    int anio, mes, dia, hora, minuto, segundo;

} Tiempo;   // nombre de la variable que se puede usar en el main

int comparaTiempos(Tiempo * t1, Tiempo * t2);

void mostrarTiempo(Tiempo t);

typedef struct {

    char * nombre;
    Tiempo ultima_mod;
} Archiv;

void ordenaAlfa(Archiv * lista, int n);

void mostrarArchivos(Archiv * lista, int n);

int main() {

    Tiempo * tie1;
    Tiempo * tie2;

    tie1 = (Tiempo*) malloc(sizeof(Tiempo));
    tie2 = (Tiempo*) malloc(sizeof(Tiempo));

    tie1->anio = 2023;
    tie1->mes = 4;
    tie1->dia = 12;

    tie2->anio = 2017;
    tie2->mes = 4;
    tie2->dia = 12;

    int resultado = comparaTiempos(tie1, tie2);

    printf("%d\n", resultado);

    mostrarTiempo(*tie2);


    // Resolución ítem A:

    int n = 5;
    Archiv * a1;

    a1 = (Archiv*) malloc(n * sizeof(Archiv));

    char * nombres[] = {"lija", "beta", "alfa", "gamma", "colapinto"};

    for (int i=0; i<n; i++) {

        a1[i].nombre = (char*) malloc((strlen(a1[i].nombre) + 1) * sizeof(char));
        strcpy(a1[i].nombre, nombres[i]);
    }


    ordenaAlfa(a1, n);

    mostrarArchivos(a1, n);

    free(tie1);
    free(tie2);

    free(a1);
    free(a1->nombre);

    return 0;
}

int comparaTiempos(Tiempo * t1, Tiempo * t2) {

    if (t1->anio < t2->anio) {
        return 1;

    }  else if (t1->anio > t2->anio) {
        return -1;
    }

    // si llegué hasta acá es porque los años son =

    if (t1->mes < t2->mes) {
        return 1;

    } else if (t1->mes > t2->mes) {
        return -1;
    }

    // si llegué hasta acá es porque los meses son =

    if (t1->dia < t2->dia) {
        return 1;

    } else if(t1->dia > t2->dia) {
        return -1;
    }

    // si llegué hasta acá es porque las fechas son =, entonces retorno 0

    return 0;
}

void mostrarTiempo(Tiempo t) {

    printf("\n%d/%d/%d", t.dia, t.mes, t.anio);
}

void ordenaAlfa(Archiv * lista, int n) {

    char temporal;

    for (int i=0; i < n; i++) {

        for (int j=0; j < n-1; j++) {

            if (strcmp(lista->nombre[j], lista->nombre[j+1]) > 0) {
                temporal = lista->nombre[j];
                lista->nombre[j] = lista->nombre[j+1];
                lista->nombre[j+1] = temporal;
            }
        }
    }
}

void mostrarArchivos(Archiv * lista, int n) {

    for(int i = 0; i<n; i++) {

        printf("%s\n", lista[i].nombre);
    }
}
