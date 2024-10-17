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
typedef TipoNodo* Coda;

//funzioni primitive
Coda* codaVuota();
bool estVuota(Coda* c);
void inCoda(Coda* c, T e);
void outCoda(Coda* c);
T primo(Coda* c);