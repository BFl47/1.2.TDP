#include "code.h"

Coda* codaVuota() {
    Coda* r = (Coda*) malloc(sizeof(Coda));
    r->data = NULL;
    r->size = 0;
    r->nelem = 0;
    return r;
}

bool estVuota(Coda* c) {
    return c->nelem == 0;
}

void inCoda(Coda* c, T e) {
    c->nelem++;
    if (c->nelem > c->size) {
        c->size = 2 * c->nelem;
        c->data = (T*) realloc(c->data, c->size * sizeof(T));
    }
    c->data[c->nelem] = e;
}

void outCoda(Coda* c) {
    if (c == NULL || c->nelem == 0) {
        printf("errore: input NULL o coda vuota");
        exit(1);
    } 
    c->nelem--;
    if (c->nelem < c->size/2) {
        c->size /= 2;
        c->data = (T*) realloc(c->data, c->size * sizeof(T));
    }
    for (int i = 1; i <= c->nelem; i++)
        c->data[i-1] = c->data[i];
}

T primo(Coda* c) {
    if (c->nelem == 0) {
        printf("errore: coda vuota");
        exit(1);
    }
    return c->data[0];
}