

int main() {
    Nodo *raiz = NULL;  // Inicializar el �rbol vac�o

    printf("=== Trabajo Pr�ctico: �rbol AVL ===\n");

    // 1. Insertar nodos predefinidos
    int valores[] = {50, 30, 70, 20, 40, 60, 80};  // Valores predefinidos
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("\nInsertando valores: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
        raiz = insertar(raiz, valores[i]);  // Llamar a tu funci�n de inserci�n
    }
    printf("\n");

    // 2. Mostrar el �rbol tras las inserciones
    printf("\n�rbol AVL (recorrido por niveles):\n");
    recorridoHorizontal(raiz);  // Usar la funci�n de recorrido por niveles

    // 3. Eliminar algunos nodos
    int eliminarValor = 30;  // Valor a eliminar
    printf("\nEliminando el valor %d...\n", eliminarValor);
    raiz = eliminar(raiz, eliminarValor);

    printf("\n�rbol AVL despu�s de eliminar %d:\n", eliminarValor);
    recorridoHorizontal(raiz);  // Mostrar el �rbol tras la eliminaci�n

    // 4. Men� interactivo
    int opcion, valor;
    do {
        printf("\nMen�:\n");
        printf("1. Insertar valor\n");
        printf("2. Eliminar valor\n");
        printf("3. Mostrar �rbol\n");
        printf("0. Salir\n");
        printf("Ingrese una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                raiz = insertar(raiz, valor);
                break;

            case 2:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &valor);
                raiz = eliminar(raiz, valor);
                break;

            case 3:
                printf("\n�rbol AVL (recorrido por niveles):\n");
                recorridoHorizontal(raiz);
                break;

            case 0:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opci�n no v�lida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}

