#include "pila.h"

Pila* pilaVuota() {
    Pila* p = (Pila*) malloc(sizeof(Pila));
    p->size = 100;
    p->nelem = 0;
    p->data = (T*) malloc(p->size * sizeof(T));
    
    return p;
}

bool estVuota(Pila* p) {
    return p->nelem == 0;
}

void push(Pila* p, T e) {
    if (p->nelem < p->size) {   
        p->data[p->nelem] = e;
        p->nelem++;
    } else
        printf("errore: array pieno\n");
}

void pop(Pila* p) {
    if (p->nelem == 0) {
        printf("errore: pila vuota");
        exit(1);
    }
    p->nelem--;
}

T top(Pila* p) {
    if (p->nelem == 0) {
        printf("errore: pila vuota");
        exit(1);
    }
    return p->data[p->nelem - 1];
}