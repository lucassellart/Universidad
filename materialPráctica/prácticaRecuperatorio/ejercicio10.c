#include <stdio.h>

int main() {

    FILE * archivo;

    archivo = fopen("./ventas.csv", "r+");

    if (archivo != NULL) {



    } else {
        printf("Error al abrir el archivo.\n");
    }

    return 0;
}
