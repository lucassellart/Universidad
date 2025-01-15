#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tiempo{

    int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

typedef struct {

    char * nombre;
    Tiempo ultima_mod;
} Archivoo;

int compara_tiempos(Tiempo *t1, Tiempo * t2);

void imprime_tiempo(Tiempo t);

// Ítem a:

void ordena_alfaa(Archivoo * lista, int n);

void imprime_archivoss(Archivoo a);

int main() {

    Tiempo * ti1;
    Tiempo * ti2;

    ti1 = (Tiempo*) malloc(sizeof(Tiempo));
    ti2 = (Tiempo*) malloc(sizeof(Tiempo));


    ti1->anio = 1972;
    ti1->mes = 5;
    ti1->dia = 24;
    ti1->hora = 13;
    ti1->minuto = 35;
    ti1->segundo = 26;

    ti2->anio = 1996;
    ti2->mes = 7;
    ti2->dia = 18;
    ti2->hora = 23;
    ti2->minuto = 44;
    ti2->segundo = 15;

    int resultado = compara_tiempos(ti1, ti2);

    printf("%d\n", resultado);

    imprime_tiempo(*ti1);
    imprime_tiempo(*ti2);

    free(ti1);
    free(ti2);


    // Resolución ítem A:  (REVISAR ENTERO, HAY ERRORES)

    Archivoo * a1;

    a1 = (Archivoo*) malloc(sizeof(Archivoo));

    a1->nombre = (char*) malloc((strlen(a1->nombre)+1) * sizeof(char));


    a1[0].nombre = "lija";
    a1[1].nombre = "beta";
    a1[2].nombre = "gamma";
    a1[3].nombre = "alfa";
    a1[4].nombre = "colapinto";

    ordena_alfaa(a1, 5);

    imprime_archivoss(*a1);

    return 0;
}


int compara_tiempos(Tiempo *t1, Tiempo * t2) {

    if (t1->anio < t2->anio) {
        return 1;
    } else if (t1->anio > t2->anio) {
        return -1;
    }

    // Si llego hasta acá es por los años son =. Entonces comparo los meses:

    if (t1->mes < t2->mes) {
        return 1;
    } else if (t1->mes > t2->mes) {
        return  -1;
    }

    // Si llego hasta acá es porque los meses son =. Entonces comparo los días:

    if (t1->dia < t2->dia) {
        return 1;
    } else if (t1->dia > t2->dia) {
        return -1;
    }

    // Si llego hasta acá es porque los dias son =. Entonces retorno 0

    return 0;
}

void imprime_tiempo(Tiempo t) {

    printf("%d/%d/%d  %d:%d:%d\n", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}

void ordena_alfaa(Archivoo * lista, int n) {    // método de ordenamiento burbuja

    for (int i=0; i<n; i++) {

        for (int j=0; j < n-1; j++){

            if (strcmp(lista[j].nombre, lista[j+1].nombre > 0)) { // comparar nombres y ordenarlos alfabéticamente

                // Acá hay que hacer el ordenamiento:
                Archivoo temporal = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temporal;
            }
        }
    }
}

void imprime_archivoss(Archivoo a) {

    printf("%s\n", a);
}
