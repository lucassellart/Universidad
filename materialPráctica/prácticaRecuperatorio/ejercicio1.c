#include <stdio.h>


int main() {

    FILE * archivo;

    archivo = fopen("./saludo.txt", "a");

    if (archivo != NULL) {

        fprintf(archivo, "\nHola mundo!\n");    // Hay que incluir el puntero al archivo

        fclose(archivo);

    } else {
        printf("Error al abrir el archivo.");
    }



    return  0;
}
