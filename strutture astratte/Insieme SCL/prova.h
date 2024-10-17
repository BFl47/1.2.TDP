#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definizione di struttura
typedef int T;
struct NodoSCL {
    T info;
    struct NodoSCL* next;
};

typedef struct NodoSCL TipoNodo;
typedef TipoNodo* Insieme;

Insieme* insiemeVuoto() {
    Insieme* r = (Insieme*) malloc(sizeof(Insieme));
    *r = NULL;
    return r;
}

bool estVuoto(Insieme *ins) {
    return *ins == NULL;
}

bool membro(Insieme* ins, T e) {
    TipoNodo* p = *ins;
    while(p != NULL) {
        if (p->info == e)
            return true;
        
        p = p->next;
    }
    return false;
}

void inserisci(Insieme* ins, T e) {
    if (!membro(ins, e)) {
        TipoNodo* n = (TipoNodo *) malloc(sizeof(TipoNodo));
        n->info = e;
        n->next = *ins;
        *ins = n;
    }
}

void elimina(Insieme* ins, T e) {
    if (*ins == NULL)
        return;
    TipoNodo* p = *ins;
    if (p->info == e) {
        *ins = p->next;
        free(p);
        return;
    }
    elimina(&((*ins)->next), e);
}

