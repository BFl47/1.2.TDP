#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definizione struttura
typedef int T;

typedef struct {
    T* data;
    int size;
    int nelem;
} Pila;

//funzioni primitive
Pila* pilaVuota();
bool estVuota(Pila* p);
void push(Pila* p, T e);
void pop(Pila* p);
T top(Pila* p);

/*Pila = Last in First out 
Array al "contrario": 
aggiungere alla fine
in caso di pop levare alla fine
il top sarà in posizione [nelem]
in caso di stampa, farlo al contrario! 
cioè da p->data[p->nelem -1] a p->data[0]*/