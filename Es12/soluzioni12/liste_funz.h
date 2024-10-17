/***************************************************
* Liste.                                           *
*                                                  *
* implementazione funzionale con memoria condivisa *
***************************************************/
#pragma once

typedef int TipoInfoSCL;
struct NodoSCL {
    TipoInfoSCL info;
    struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo * TipoSCL;

// Tipo astratto TipoLista
typedef TipoNodo * TipoLista;

// Operazioni
TipoLista listaVuota();                         // crea lista vuota
int estVuota(TipoLista l);                      // controllo se vuota
TipoLista cons(TipoInfoSCL e, TipoLista l);     // creo lista aggiungendo per primo
TipoInfoSCL car(TipoLista l);                   // leggo valore del primo
TipoLista cdr(TipoLista l);                     // ritorno coda della lista

void printlist(TipoLista l);
