#include <stdio.h>
#include <string.h>

struct persona {

    char nombre[30];
    int edad;
}per1, per2;


int main () {

    //struct persona per1, per2;

    strcpy(per1.nombre, "BETURRI");
    strcpy(per2.nombre, "MESSI");


    per1.edad = 24;
    per2.edad = 37;

    printf("Nombre y Edad: %s, %d\n", per1.nombre, per1.edad);
    printf("\nNombre y Edad: %s, %d\n", per2.nombre, per2.edad);





    return 0;
}
