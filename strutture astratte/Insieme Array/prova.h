#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definizione struttura
typedef int T;

typedef struct {
    int size;           //dimensione
    int nelem;          //n° elem validi
    T* data;            //array
} Insieme;

//funzioni
Insieme* insiemeVuoto() {
    Insieme* ins = (Insieme*) malloc(sizeof(Insieme));
    ins->size = 100;
    ins->nelem = 0;
    ins->data = (T*) malloc(ins->size * sizeof(T));
    return ins;
}

bool estVuoto(Insieme* ins) {
    return ins->nelem == 0;
}

bool membro(Insieme* ins, T e) {
    bool r = false;
    for (int i = 0; i < ins->nelem; i++)
        r = ins->data[i] == e;
}

void inserisci(Insieme* ins, T e) {
    if (!membro(ins, e)) {
        if (ins->nelem < ins->size) {
            ins->data[ins->nelem] = e;
            ins->nelem++;
        } else printf("errore: array pieno\n");
    }
}

void elimina(Insieme* ins, T e) {
    int i = 0;
    while (i < ins->nelem && ins->data[i] != e) 
        i++;
    if (i == ins->nelem) {}
    else {
        for (int j = i; j < ins->nelem-1; j++)
            ins->data[j] = ins->data[j+1];
        ins->nelem--;
    }
}