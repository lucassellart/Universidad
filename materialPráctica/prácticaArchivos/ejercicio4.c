#include <stdio.h>

int main() {

    FILE * pArchivo;

    pArchivo = fopen("./notas.txt", "a");   // abrir el archivo en modo "añadir" (append)

    if (pArchivo != NULL) { // verifica si el archivo se abre correctamente
        fputs("Nueva nota: 100\n", pArchivo);

        if (fclose(pArchivo)) { // devolvió fclose un valor distinto de 0 ?
            printf("Error al cerrar el archivo\n");
        }

    } else {
        printf("Error al abrir el archivo.\n");
    }

    return 0;
}
