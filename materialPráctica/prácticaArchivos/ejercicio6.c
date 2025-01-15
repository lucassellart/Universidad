#include <stdio.h>

int alfanumerico(int caracter);

int main() {

    FILE * pArchivo;

    pArchivo = fopen("./texto.txt", "r");

    int contador = 0;
    int caracter;
    int enPalabra = 0;  // 0 = fuera de una palabra, 1 = dentro de una palabra

    if (pArchivo != NULL) {

        while ((caracter = fgetc(pArchivo)) != EOF) {   // leer el archivo caracter por caracter

            if (alfanumerico(caracter)) {   // verificar si el caracter es alfanumérico
                if (enPalabra == 0) {
                    enPalabra = 1;
                    contador++;
                }
            } else {
                enPalabra = 0;
            }
        }

        printf("El numero total de palabras en el archivos es: %d\n", contador);

        fclose(pArchivo);

    } else {
        printf("Error al abrir el archivo.\n");
    }



    return 0;
}

int alfanumerico(int caracter) {

    return ((caracter >= 'a' && caracter <= 'z') ||
            (caracter >= 'A' && caracter <= 'Z') ||
            (caracter >= 0 && caracter <= 9));
}
