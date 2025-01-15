#include <stdio.h>

int main() {

    FILE * pArch;

    pArch = fopen("./texto.txt", "w");

    if (pArch != NULL) {

        fputs("Manzana\n", pArch);
        fputs("Banana\n", pArch);
        fputs("Naranja\n", pArch);
        fputs("Pera\n", pArch);
        fputs("Uva\n", pArch);

        if (fclose(pArch)) {
            printf("Error al cerrar el archivo\n");
        }
    } else {
        printf("Error al abrir el archivo\n");
    }

    return 0;
}
