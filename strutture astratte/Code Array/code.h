#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//definizione struttura
typedef int T;

typedef struct {
    T* data;
    int size;
    int nelem;
} Coda;

//definizione funzioni
Coda* codaVuota();
bool estVuota(Coda* c);
void inCoda(Coda* c, T e);
void outCoda(Coda* c);
T primoCoda(Coda* c);