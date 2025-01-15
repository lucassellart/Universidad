#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {

    int dato;                   // Valor del nodo
    int altura;                 // Altura del nodo
    struct Nodo * h_izq;        // Puntero al hijo izquierdo
    struct Nodo * h_der;        // Puntero al hijo derecho
                                // Los hijos  izq. y der. de un nodo deben ser nodos de la misma estructura
} Nodo;

// Estructura para la cola

typedef struct Cola {       // Se utiliza para  poder recorrer los nodos por niveles

    Nodo ** arreglo;        // Array de punteros a nodos, facilita el recorrido por niveles
    int frente;             // índice del primer elemento de la cola
    int ultimo;             // Índice del último elemento de la cola
    int capacidad;          // Cantidad de elementos a almacenar

} Cola;

// Calculos de altura y balanceo:

int calculoAltura(Nodo * n);

void actualizarAltura(Nodo * n);

int calculoFactorBalanceo(Nodo * n);

int max(int a, int b);      // Obtener el valor máximo entre 2 números

// Rotaciones:

Nodo * rotacionDerecha(Nodo * y);

Nodo * rotacionIzquierda(Nodo * x);

Nodo * rotacionIzquierdaDerecha(Nodo * n);

Nodo * rotacionDerechaIzquierda(Nodo * n);

// Insertar, eliminar, crear nodo:

Nodo * insertar(Nodo * n, int valor);

Nodo * obtenerMinimo(Nodo * n);

Nodo * eliminar(Nodo * n, int valor);

Nodo * crearNodo(int valor);

// Recorrido por niveles:

void imprimirEnOrden(Nodo * raiz);

// Funciones para manejar la cola:

Cola * crearCola(int capacidad);

int colaVacia(Cola * cola);

void encola(Cola * cola, Nodo * nodo);

Nodo * desencola(Cola * cola);

void recorridoHorizontal(Nodo * nodo);

void liberarCola(Cola * cola);

// Funciones para el main:

void pruebaAVL();               // Función para prueba de las funcionalidades del AVL:

void menuInteractivo();         // Función para que el usuario pruebe las operaciones del AVL.

void liberarArbol(Nodo * n);    // Función para liberar todos los nodos del Árbol AVL

int main() {

    int opcion;

    printf("Arbol AVL: \n");
    printf("Que accion desea realizar?\n");
    printf("1. Testear Arbol AVL:\n");
    printf("2. Menu Interactivo:\n");
    printf("\nIngrese su eleccion:\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        pruebaAVL();

    } else if (opcion == 2) {
        menuInteractivo();

    } else {
        printf("Opcion incorrecta. Por favor, intente nuevamente...\n");
    }


    return 0;
}

int calculoAltura(Nodo * n) {

    if (n == NULL) {
        return 0;       // Si el nodo es NULL, la altura es 0
    } else {
        return n->altura;
    }
}

void actualizarAltura(Nodo * n) {

    if (n != NULL) {
        n->altura = 1 + max(calculoAltura(n->h_izq), calculoAltura(n->h_der));
    }
    // Se suma 1 para incluir la altura del nodo actual
}

int max(int a, int b) {

    return (a > b) ? a : b;

    // Los operadores '? :' son la abreviatura del condicional if-else.
    // Calcula el valor máximo entre 2 números
}

void imprimirEnOrden(Nodo * raiz) {     // Imprime los valores de los nodos en secuencia ascendente

    if (raiz != NULL) {
        imprimirEnOrden(raiz->h_izq);
        printf("%d ", raiz->dato);
        imprimirEnOrden(raiz->h_der);
    }
}

int calculoFactorBalanceo(Nodo * n) {

    if (n == NULL) {
        return 0;
    } else {
        return calculoAltura(n->h_izq) - calculoAltura(n->h_der);
    }
}

Nodo * rotacionDerecha(Nodo * y) {

    // 'y' es el nodo desbalanceado
    // 'x' es el hijo izquierdo de 'y'
    // 'T2' es el hijo derecho de 'x'

    // Asignaciones:
    Nodo * x = y->h_izq;
    Nodo * T2 = x->h_der;

    // Rotación:                // 'x' pasa a ser la nueva raíz del subarbol
    x->h_der = y;               // El nodo 'y' pasa a ser el hijo derecho de 'x'
    y->h_izq = T2;              // 'T2' pasa a ser el hijo izquierdo de 'y'

    actualizarAltura(y);        // Nuevo hijo derecho
    actualizarAltura(x);        // Nueva raíz

    return x;       // Retornar nueva raíz
}

Nodo * rotacionIzquierda(Nodo * x) {

    // 'x' es el nodo desbalanceado
    // 'y' es el hijo derecho de 'x'
    // 'T2' es el hijo izquierdo de 'y'

    Nodo * y = x->h_der;
    Nodo * T2 = y->h_izq;

    // Rotación          // 'y' pasa a ser la raíz del subárbol
    y->h_izq = x;        // 'x' se convierte en el hijo izquierdo de 'y'
    x->h_der = T2;       // 'T2' se convierte en el nuevo hijo derecho de 'x'

    // Nodos afectados tras la rotación, actualizo sus alturas
    actualizarAltura(x);    // Nuevo hijo izquierdo
    actualizarAltura(y);    // Nueva raíz

    return y;   // Retorno 'y'. Nueva raíz del subárbol tras la rotación
}

Nodo * rotacionIzquierdaDerecha(Nodo * n) {     // Puntero al nodo desbalanceado

    n->h_izq = rotacionIzquierda(n->h_izq);     // Rotación simple a la izq. sobre el hijo izq. Corregir el desbalance en el hijo izq. de 'n'

    return rotacionDerecha(n);                  // Rotación simple a la derecha sobre el nodo desbalanceado
}

Nodo * rotacionDerechaIzquierda(Nodo * n) {

    n->h_der = rotacionDerecha(n->h_der);

    return rotacionIzquierda(n);
}

Nodo * insertar(Nodo * n, int valor) {

    if (n == NULL) {        // Espacio para insertar un nuevo nodo
        return crearNodo(valor);
    }

    if (valor < n->dato) {
        n->h_izq = insertar(n->h_izq, valor);

    } else if (valor > n->dato) {
        n->h_der = insertar(n->h_der, valor);

    } else {
        return n;   // Valor duplicado no permitido
    }

    // Actualizar altura del nodo:
    actualizarAltura(n);

    // Calcular factor de balanceo:
    int balance = calculoFactorBalanceo(n);

    // Casos de desbalance:
    // Caso 1: left-left
    if (balance > 1 && valor < n->h_izq->dato) {
        return rotacionDerecha(n);
    }

    // Caso 2: right-right
    if (balance < -1 && valor > n->h_der->dato) {
        return rotacionIzquierda(n);
    }

    // Caso 3: left-right
    if (balance > 1 && valor > n->h_izq->dato) {
        return rotacionIzquierdaDerecha(n);
    }

    // Caso 4: right-left
    if (balance < -1 && valor < n->h_der->dato) {
        return rotacionDerechaIzquierda(n);
    }

    return n;
}

Nodo * obtenerMinimo(Nodo * n) {            // Encontrar el valor mínimo del subárbol

    Nodo * actual = n;                      // Puntero para recorrer el arbol

    while (actual->h_izq != NULL) {         // Encontrar el hijo más a la izquierda
        actual = actual->h_izq;
    }
    return actual;                          // Retorno el nodo más a la izquierda
}

Nodo * eliminar(Nodo * n, int valor) {

    if (n == NULL) {
        return n;
    }

    if (valor < n->dato) {
        n->h_izq = eliminar(n->h_izq, valor);

    } else if (valor > n->dato) {
        n->h_der = eliminar(n->h_der, valor);

    } else {
        // Nodo encontrado

        if ((n->h_izq == NULL) || (n->h_der == NULL)) {

            Nodo * temp;

            if (n->h_izq != NULL) {
                temp = n->h_izq;
            } else {
                temp = n->h_der;
            }

            if (temp == NULL) {
                // No hay hijos
                temp = n;
                n = NULL;       // El nodo es eliminado
            } else {
                // Un solo hijo
                *n = *temp;     // Copiar los datos del nodo hijo al nodo actual
            }
            free(temp);         // Se reservó memoria en la función de crearNodo

        } else {

            // Nodo con 2 hijos:
            Nodo * sucesor = obtenerMinimo(n->h_der);

            n->dato = sucesor->dato;

            n->h_der = eliminar(n->h_der, sucesor->dato);
        }
    }

    if (n == NULL) {        // Me aseguro que de no seguir actualizando la altura ni calcular el balance en un nodo NULL
        return n;
    }

    // Actualizar altura:
    actualizarAltura(n);

    // Calcular factor de balanceo:
    int balance = calculoFactorBalanceo(n);

    // Casos de desbalance:
    // Caso 1: left-left
    if (balance > 1 && calculoFactorBalanceo(n->h_izq) >= 0) {
        return rotacionDerecha(n);
    }

    // Caso 2: left-right
    if (balance > 1 && calculoFactorBalanceo(n->h_izq) < 0) {
        return rotacionIzquierdaDerecha(n);
    }

    // Caso 3: right-right
    if (balance < -1 && calculoFactorBalanceo(n->h_der) <= 0) {
        return rotacionIzquierda(n);
    }

    // Caso 4: right-left
    if (balance < -1 && calculoFactorBalanceo(n->h_der) > 0) {
        return rotacionDerechaIzquierda(n);
    }

    return n;
}

Nodo * crearNodo(int valor) {

    Nodo * nuevo = (Nodo*)malloc(sizeof(Nodo));     // La memoria se libera en la función eliminar

    nuevo->dato = valor;    // Asigna el valor al nodo
    nuevo->altura = 1;      // Nuevo nodo agregado como una hoja
    nuevo->h_izq = NULL;    // Inicializa hijo izquierdo a NULL
    nuevo->h_der = NULL;    // Inicializa hijo derecho a NULL

    return nuevo;           // Nodo creado
}

Cola * crearCola(int capacidad) {

    Cola * cola = (Cola*)malloc(sizeof(Cola));

    cola->arreglo = (Nodo**)malloc(capacidad * sizeof(Nodo*));

    cola->frente = 0;               // Posición inicial del arreglo
    cola->ultimo = -1;              // La cola está vacía, no hay ningún elemento todavía
    cola->capacidad = capacidad;    // La capacidad es un valor que se recibe como argumento de la función.

    return cola;
}

int colaVacia(Cola * cola) {        // La función devuelve (1) verdadero si la cola está vacía
                                    // ó (0) falso si no está vacía
    return cola->ultimo < cola->frente;
}

void encola(Cola * cola, Nodo * nodo) {     // La función agrega un puntero nodo a la cola

    if (cola->ultimo < cola->capacidad -1) {    // Esta condición verifica si hay espacio para agregar un nuevo elemento

        cola->ultimo++;
        cola->arreglo[cola->ultimo] = nodo;
    }
    // cola->capacidad -1 es el índice máximo para la cola (los índices del array empiezan en 0)
}

Nodo * desencola(Cola * cola) {

    if (!colaVacia(cola)) {

        Nodo * nodo = cola->arreglo[cola->frente];
        cola->frente++;
        return nodo;
    }
    return NULL;
}

void recorridoHorizontal(Nodo * nodo) {

    if (nodo == NULL) {     // No hay nodos, árbol vacío
        printf("Arbol vacio.\n");
        return;
    }

    Cola * cola = crearCola(100);
    encola(cola, nodo);

    while(!colaVacia(cola)) {

        Nodo * nodoNuevo = desencola(cola);
        printf("%d ", nodoNuevo->dato);

        if (nodoNuevo->h_izq != NULL) {     // Encolar hijo izq. si existe
            encola(cola, nodoNuevo->h_izq);
        }
        if (nodoNuevo->h_der != NULL) {     // Encolar hijo der. si existe
            encola(cola, nodoNuevo->h_der);
        }
    }

    printf("\n");
    liberarCola(cola);
}

void liberarCola(Cola * cola) {

    free(cola->arreglo);        // Libero memoria del array interno
    free(cola);                 // Libero memoria de la estructura de la cola
}

void liberarArbol(Nodo * n) {

    if (n == NULL) {
        return;
    }

    // Eliminar recursivamente los subárboles izquierdo y derecho
    liberarArbol(n->h_izq);
    liberarArbol(n->h_der);

    free(n);
}

void pruebaAVL() {

    Nodo * raiz = NULL;

    // Insertar valores:

    raiz = insertar(raiz, 10);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 25);

    // Mostrar el árbol:

    printf("\nMuestra AVL en orden: \n");
    imprimirEnOrden(raiz);      // Verifico que los elementos se ordenen correctamente
    printf("\n");

    printf("\nRecorrido por niveles: \n");
    recorridoHorizontal(raiz);  // Imprimo los elementos del árbol nivel por nivel. Verifico que los balances funciones correctamente.

    // Eliminar un nodo y verificar balance:
    raiz = eliminar(raiz, 30);

    printf("\nLuego de eliminar (30):\n");
    printf("\nMuestra AVL en orden:\n");
    imprimirEnOrden(raiz);
    printf("\n");

    printf("\nRecorrido por niveles:\n");
    recorridoHorizontal(raiz);
    printf("\n");

    liberarArbol(raiz);     // Liberar memoria del Árbol antes de salir
}

void menuInteractivo() {

    Nodo * raiz = NULL;
    int opcion, valor;

    while (1) {     // Bucle infinito que finaliza con 'return'. Se ejecuta hasta que el usuario decide salir (opcion 5)
        printf("\nMenu Arbol AVL:\n");
        printf("1. Insertar un nodo:\n");
        printf("2. Eliminar un nodo:\n");
        printf("3. Mostrar Arbol en orden:\n");     // Imprime los elementos en orden ascendente
        printf("4. Mostrar recorrido por niveles:\n");
        printf("5. Salir\n");

        printf("\nIngrese una opcion:\n");
        scanf("%d", &opcion);

        switch (opcion) {

            case 1:
                printf("Ingrese el valor a insertar: \n");
                scanf("%d", &valor);
                raiz = insertar(raiz, valor);
                printf("Nodo insertado.\n");
                break;

            case 2:
                printf("Ingrese el valor a eliminar: \n");
                scanf("%d", &valor);
                raiz = eliminar(raiz, valor);
                printf("Nodo eliminado.\n");
                break;

            case 3:
                printf("Arbol en orden: \n");
                imprimirEnOrden(raiz);
                printf("\n");
                break;

            case 4:
                printf("Arbol por niveles: \n");
                recorridoHorizontal(raiz);
                printf("\n");
                break;

            case 5:
                printf("Saliendo del programa...\n");

                liberarArbol(raiz);     // Liberar memoria del Árbol antes de salir

                return;     // Se usa para salir de la función del menú interactivo
                            // El control vuelve al main
            default:
                printf("Opcion incorrecta. Por favor intente nuevamente...\n");
        }
    }
}
