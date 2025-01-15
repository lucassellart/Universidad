

int main() {
    Nodo *raiz = NULL;  // Inicializar el árbol vacío

    printf("=== Trabajo Práctico: Árbol AVL ===\n");

    // 1. Insertar nodos predefinidos
    int valores[] = {50, 30, 70, 20, 40, 60, 80};  // Valores predefinidos
    int n = sizeof(valores) / sizeof(valores[0]);

    printf("\nInsertando valores: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
        raiz = insertar(raiz, valores[i]);  // Llamar a tu función de inserción
    }
    printf("\n");

    // 2. Mostrar el árbol tras las inserciones
    printf("\nÁrbol AVL (recorrido por niveles):\n");
    recorridoHorizontal(raiz);  // Usar la función de recorrido por niveles

    // 3. Eliminar algunos nodos
    int eliminarValor = 30;  // Valor a eliminar
    printf("\nEliminando el valor %d...\n", eliminarValor);
    raiz = eliminar(raiz, eliminarValor);

    printf("\nÁrbol AVL después de eliminar %d:\n", eliminarValor);
    recorridoHorizontal(raiz);  // Mostrar el árbol tras la eliminación

    // 4. Menú interactivo
    int opcion, valor;
    do {
        printf("\nMenú:\n");
        printf("1. Insertar valor\n");
        printf("2. Eliminar valor\n");
        printf("3. Mostrar árbol\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
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
                printf("\nÁrbol AVL (recorrido por niveles):\n");
                recorridoHorizontal(raiz);
                break;

            case 0:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}

