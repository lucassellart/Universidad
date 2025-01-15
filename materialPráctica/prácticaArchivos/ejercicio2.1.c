#include <stdio.h>

int main() {

    FILE * pArchiv;

    pArchiv = fopen("./datos.txt", "w");

    if (pArchiv != NULL) {

        fputs("Alejandro Rodriguez\n", pArchiv);
        fputs("Diego Botallo\n", pArchiv);
        fputs("Federico Severino\n", pArchiv);

        if (fclose(pArchiv)) {
            printf("Error al cerrar el archivo\n");
        }
    } else {
        printf("Error al crear el archivo\n");
    }

    return 0;
}
