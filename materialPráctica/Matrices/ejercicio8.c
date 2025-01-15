#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* dia(int n) {

char * diaRetorno = NULL;

    if(n < 1 || n > 8){

        return NULL;
    }



    if (n == 1) {
        diaRetorno = (char*)malloc(6*sizeof(char));
        strcpy(diaRetorno,"Lunes");
        diaRetorno[5] = '\0';
    } else if (n == 2) {
        diaRetorno = (char*)malloc(7*sizeof(char));
        strcpy(diaRetorno,"Martes");
        diaRetorno[6] = '\0';
    } else if (n == 3) {

    } else if (n == 4) {

    } else if (n == 5) {

    } else if (n == 6) {

    } else {

    }

    return diaRetorno;
}


int main() {

    int numero;

    printf("Ingrese un numero entre 1 y 7: ");
    scanf("%d", &numero);

    char* day = dia(numero);
    if( day == NULL)
        printf("Ingreso un numero que no es dia\n");
    else
        printf("Ingreso el dia %s \n", day);


    return 0;
}

