
#include <stdio.h>
#include <stdlib.h>

#include "liste_funz.h"


TipoLista listaVuota() { return NULL; }

int estVuota(TipoLista l) { return (l == NULL); }

TipoLista cons(TipoInfoSCL e, TipoLista l)
{
  TipoLista nuovo = (TipoLista)malloc(sizeof(TipoNodo));
  nuovo->info = e;
  nuovo->next = l;
  return nuovo;
}

TipoInfoSCL car(TipoLista l)
{
  if (l == NULL)
  {
    printf(" ERRORE : lista vuota \n ");
    exit(1);
  }
  return l->info;
}

TipoLista cdr(TipoLista l)
{
  if (l == NULL)
  {
    printf(" ERRORE : lista vuota \n ");
    exit(1);
  }
  return l->next;
}

void printlist_aux(TipoLista l)
{
	if (estVuota(l)) return;
	printf("%d, ", car(l));
	printlist_aux(cdr(l));
}


void printlist(TipoLista l)
{
	printlist_aux(l);
	printf("\n\n");
}
