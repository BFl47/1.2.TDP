#include "pile.h"

Pila* pilaVuota() {
    return (Pila*) malloc(sizeof(Pila));
}

bool estVuota(Pila* p) {
    return *p == NULL;
}

void pushPila(Pila* p, T e) {
    TipoNodo* tmp = (TipoNodo *) malloc(sizeof(TipoNodo));
    tmp->info = e;
    tmp->next = *p;
    *p = tmp;
}

void popPila(Pila* p) {
    if (*p == NULL) return;
    TipoNodo* tmp = *p;
    *p = (*p)->next;
    free(tmp);
}

T topPila(Pila* p) {
    if (*p == NULL) {
        printf("errore: pila vuota");
        exit(1);
    }
    return (*p)->info;
}