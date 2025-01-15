#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int n;
    int * coeficiente;
} Polinomio;

//Ítem a:

Polinomio * creaPolinomio(int orden);

void cargaPolinomio(Polinomio * p);

void mostrarPolinomio(Polinomio * p);

//ítem b:

void setCoef(int n, int c, Polinomio * p);

//Ítem c:

int getCoef(int n, Polinomio * p);

//Ítem e:

Polinomio * sum(Polinomio * p1, Polinomio * p2);

//Ítem f:

Polinomio * mult(Polinomio * p1, Polinomio * p2);

//Ítem h:

void destruyePolinomio(Polinomio * p);

int main() {

    srand(time(NULL));

    Polinomio * poli1;
    Polinomio * poli2;

    poli1 = creaPolinomio(8);
    poli2 = creaPolinomio(8);

    cargaPolinomio(poli1);
    cargaPolinomio(poli2);


    mostrarPolinomio(poli2);

    setCoef(3, 50, poli1);

    mostrarPolinomio(poli1);

    int resultado = getCoef(2, poli1);

    printf("\n%d\n", resultado);


    Polinomio * resul = sum(poli1, poli2);

    mostrarPolinomio(resul);

    Polinomio * multip = mult(poli1, poli2);

    mostrarPolinomio(multip);


    destruyePolinomio(poli1);
    destruyePolinomio(poli2);
    destruyePolinomio(resul);
    destruyePolinomio(multip);


    return 0;
}

void destruyePolinomio(Polinomio * p) {

    free(p->coeficiente);
    free(p);
}

Polinomio * creaPolinomio(int orden) {

    Polinomio * p1;

    p1 = (Polinomio*) malloc(sizeof(Polinomio));

    p1->n = orden;

    p1->coeficiente = (int*) malloc((orden+1) * sizeof(int));

    return p1;
}

void cargaPolinomio(Polinomio * p) {

    for(int i=0; i <= p->n; i++) {

        p->coeficiente[i] = rand() % 10 + 1;
    }
}

void mostrarPolinomio(Polinomio * p) {

    for(int i=0; i <= p->n; i++) {

        printf("%d ", p->coeficiente[i]);
    }
    printf("\n");
}

void setCoef(int n, int c, Polinomio * p) {

    if (n >= 0 && n <= p->n) {

        p->coeficiente[n] = c;
    } else {
        printf("Fuera de rango...");
    }
}

int getCoef(int n, Polinomio * p) {

    if (n >= 0 && n <= p->n) {

        p->coeficiente[n];
    } else {
        printf("Fuera de rango...");
        return -1;
    }

    return n;
}

Polinomio * sum(Polinomio * p1, Polinomio * p2) {

    Polinomio * suma;

    suma = (Polinomio*) malloc(sizeof(Polinomio));

    suma->coeficiente = (int*) malloc(((suma -> n)+1) * sizeof(int)); //Acá estoy reservando espacio en memoria para los coeficientes

    suma->n = p1->n;        // Para setear el grado del polinomio

    for(int i=0; i <= suma->n; i++) {

        suma->coeficiente[i] = p1->coeficiente[i] + p2->coeficiente[i];
    }

    return suma;
}


Polinomio * mult(Polinomio * p1, Polinomio * p2) {

    Polinomio * multiplicacion;

    multiplicacion = (Polinomio*) malloc(sizeof(Polinomio));

    multiplicacion->coeficiente = (int*) malloc(((multiplicacion->n) + 1) * sizeof(int));       // El '+1' es por el término independiente del polinomio

    multiplicacion->n = p1->n;      // Para setear el grado del polinomio.

    for(int i=0; i <= multiplicacion->n; i++) {

        multiplicacion->coeficiente[i] = p1->coeficiente[i] * p2->coeficiente[i];
    }


    return multiplicacion;
}

