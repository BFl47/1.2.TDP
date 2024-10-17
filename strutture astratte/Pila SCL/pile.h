#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definizione struttura
typedef int T;

struct NodoSCL {
    T info;
    struct NodoSCL* next;
};

typedef struct NodoSCL TipoNodo;
typedef TipoNodo* Pila;

//funzioni primitive
Pila* pilaVuota();
bool estVuota(Pila* p);
void pushPila(Pila* p, T e);
void popPila(Pila* p);
T topPila(Pila* p);