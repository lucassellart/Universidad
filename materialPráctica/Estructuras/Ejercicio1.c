#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct tiempo {

    int anio, mes, dia, hora, minuto, segundo;
}Tiempo;


typedef struct {

    char * nombre;
    Tiempo ultima_mod;
}Archivo;


int compara_tiempos(Tiempo * t1, Tiempo * t2);

void imprime_tiempo(Tiempo t);


void ordena_alfa(Archivo * lista, int n);

void imprime_archivos(Archivo *lista, int n);

void ordena_temporal(Archivo * lista, int n);

int main() {

    int r;

    Tiempo * ti1;
    Tiempo * ti2;

    ti1 = (struct tiempo*) malloc(sizeof(struct tiempo));
    ti2 = (struct tiempo*) malloc(sizeof(struct tiempo));

    ti1 -> anio = 2034;
    ti1 -> mes = 3;
    ti1 -> dia = 29;

    ti1 -> hora = 17;
    ti1 -> minuto = 40;
    ti1 -> segundo = 52;



    ti2 -> anio = 2034;
    ti2 -> mes = 3;
    ti2 -> dia = 29;

    ti2 -> hora = 13;
    ti2 -> minuto = 24;
    ti2 -> segundo = 38;

    r = compara_tiempos(ti1, ti2);

    printf("%d\n", r);

    imprime_tiempo(*ti2);



    // Resolución ítem a:

    int cantidad = 5;
    int fechas = 5;

    Archivo * lista;      // Acá estoy creando un array de esctructuras de tamaño 'cantidad'

    lista = (Archivo*) malloc(cantidad * sizeof(Archivo));


    lista[0].nombre = "lija";
    lista[1].nombre = "beta";
    lista[2].nombre = "alfa";
    lista[3].nombre = "gama";
    lista[4].nombre = "cixu";


    printf("\nArchivos antes de ordenar: \n");
    imprime_archivos(lista, cantidad);

    ordena_alfa(lista, cantidad);

    printf("\nArchivos despues de ordenar: \n");
    imprime_archivos(lista, cantidad);



    ordena_temporal(lista, fechas);


    free(lista);

    return 0;
}

void ordena_temporal(Archivo * lista, int n) {

    Archivo auxiliar;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n - 1; j++) {

            if (compara_tiempos(&lista[j].ultima_mod, &lista[j+1].ultima_mod) > 0) {

                auxiliar = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = auxiliar;
            }
        }
    }
}

void ordena_alfa(Archivo * lista, int n) {

    Archivo auxiliar;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n - 1; j++) {

            if (strcmp(lista[j].nombre, lista[j+1].nombre) > 0) {

                auxiliar = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = auxiliar;
            }
        }
    }

}


void imprime_archivos(Archivo *lista, int n) {

    for(int i = 0; i<n; i++) {

        printf("%s\n", lista[i].nombre);
    }
}


int compara_tiempos(Tiempo * t1, Tiempo * t2) {


    if (t1->anio < t2->anio) {
        return 1;
    } else if (t1->anio > t2->anio) {
        return -1;
    }

    // Si llego hasta acá es porque los años son iguales. Entonces comparo los meses:

    if (t1->mes < t2->mes) {
        return 1;
    } else if (t1->mes > t2->mes) {
        return -1;
    }

    // Si llego hasta acá es porque los meses son iguales. Entonces comparo los días:

    if (t1->dia < t2->dia) {
        return 1;
    } else if (t1->dia > t2->dia) {
        return -1;
    }

    // Si llego hasta acá es porque ambas fechas son iguales. Entonces retorno cero.

    return 0;
}

void imprime_tiempo(Tiempo t) {

    printf("\n%d/%d/%d  %d:%d:%d\n", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}


