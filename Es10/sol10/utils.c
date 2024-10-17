
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "utils.h"

void printIntArray(int* arr, int len)
{
    printf("{");
    for(int i=0; i<len; i++)
    {
        printf("%d", arr[i]);
        if(i<len-1) printf(", ");
    }
    printf("}\n");
}

Coda* initCoda(int* arr, int len)
{
    Coda * c = codaVuota();
    for(int i=0; i<len; i++)
    {
        inCoda(c, arr[i]);
    }
    return c;
}
Coda* copiaCoda(Coda* coda)
{
    Coda* nuovaCoda = codaVuota();
    Coda* nodo = coda;
    while((*nodo)!=NULL)
    {
        inCoda(nuovaCoda, (*nodo)->info);
        nodo = &((*nodo) -> next);
    }
    return nuovaCoda;
}

void printCoda(Coda* c)
{
    printf("{");
    Coda* nodo = c;
    while((*nodo) != NULL)
    {
        if(nodo != c) printf(", ");
        printf("%d", (*nodo) -> info);

        nodo = &((*nodo) -> next);
    }
    printf("}");
}

Pila* initPila(int* arr, int len)
{
    Pila * c = pilaVuota();
    for(int i=0; i<len; i++)
    {
        inPila(c, arr[i]);
    }
    return c;

}
void printPila(Pila* c)
{
    printf("{");
    TipoNodo * nodo = *c;
    while(nodo != NULL)
    {
        if(nodo != *c) printf(", ");
        printf("%d", nodo -> info);

        nodo = nodo -> next;
    }
    printf("}");
}