#include "coda.h"

Coda* codaVuota() {
    return (Coda*) malloc(sizeof(Coda));
}

bool estVuota(Coda* c) {
    return *c == NULL;
}

void inCoda(Coda* c, T e) {
    if (*c == NULL) {
        *c = (Coda) malloc(sizeof(TipoNodo));
        (*c)->info = e;
        (*c)->next = NULL;
    } else
        inCoda(&((*c)->next), e);
}

void outCoda(Coda* c) {
    if (c == NULL || *c == NULL) 
        printf("Errore: input NULL o coda vuota");
    Coda tmp = *c;
    *c = (*c)->next;
    free(tmp);
}

T primo(Coda* c) {
    if (*c == NULL) {
        printf("Errore: coda vuota");
        exit(1);
    }
    return (*c)->info;
}