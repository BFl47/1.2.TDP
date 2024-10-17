#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "scl.h"


// Ausiliarie

TipoSCL listPushFront(TipoSCL p0, int info)
{
  TipoSCL new_element = (TipoSCL)malloc(sizeof(TipoNodoSCL));
  new_element->next = p0;
  new_element->info = info;
  return new_element;
}


TipoSCL listPushBack(TipoSCL l, int info)
{
  TipoSCL new_element = (TipoSCL)malloc(sizeof(TipoNodoSCL));
  new_element->next = NULL;
  new_element->info = info;

  if (l == NULL)
  {
    return new_element;
  }
  TipoSCL aux = l;
  while (aux->next != NULL)
  {
    aux = aux->next;
  }
  aux->next = new_element;
  return l;
}


TipoSCL copyList(TipoSCL list)
{
  TipoSCL head = NULL;

  while (list)
  {
    head = listPushBack(head, list->info);
    list = list->next;
  }
  return head;
}


TipoSCL createRandomList(int size)
{
  TipoSCL random_list = NULL;
  for (int i = 0; i < size; ++i)
    random_list = listPushFront(random_list, rand() % 20 - 10);
  return random_list;
}


bool equalLists(TipoSCL l1, TipoSCL l2)
{
	if (l1 == NULL && l2 == NULL) return true;
	if (l1 == NULL || l2 == NULL) return false;
	if (l1->info != l2->info) return false;
	return equalLists(l1->next, l2->next);
}


void printList(TipoSCL l)
{
  if (l == NULL) {
		puts("NULL");
	}
  TipoSCL aux = l;
	printf("[ ");
  while (aux != NULL)
  {
    printf("%.2f", aux->info);
    aux = aux->next;
		if (aux != NULL) {
			printf(", ");
		}
  }
	printf(" ]");
}


void freeList(TipoSCL list)
{
  if (list == NULL)
    return;
	freeList(list->next);
	free(list);
}


// Esercizi

int scl_len(TipoSCL scl) {
  if(scl == NULL)
    return 0;
  return 1 + scl_len(scl->next);
}


float scl_sum(TipoSCL scl) {
  if(scl == NULL)
    return 0.0;
  return (scl->info) + scl_sum(scl->next);
}


// Funzione ausiliaria per scl_media. Sommo e conto insieme
static float scl_media_aux(TipoSCL scl, float sum, int count) {
	if (scl == NULL) {
		return sum / count;
	}
	return scl_media_aux(scl->next, scl->info + sum, count + 1);
}


float scl_media(TipoSCL scl) {
	return scl_media_aux(scl, 0, 0);
}


float scl_dot(TipoSCL scl1, TipoSCL scl2){

  if (scl1 == NULL) {  // Assumo che entrambe abbiano la stessa lunghezza
    return 0;
	}
	float prod = scl1->info * scl2->info;
  return prod + scl_dot(scl1->next, scl2->next);
}


void scl_duplicate_pos(TipoSCL scl, int pos) {
	if (scl == NULL) return;

	if (pos <= 0) {
		TipoNodoSCL *nodo = (TipoNodoSCL *)malloc(sizeof(TipoNodoSCL));
		nodo->info = scl->info;
		nodo->next = scl->next;
		scl->next = nodo;
		return;
	}

	scl_duplicate_pos(scl->next, pos - 1);
}


TipoSCL scl_positives(TipoSCL scl) {
	if (scl == NULL) {
		return NULL;
	}
	if (scl->info >= 0) {
		TipoNodoSCL *nodo = (TipoNodoSCL *)malloc(sizeof(TipoNodoSCL));
		nodo->info = scl->info;
		nodo->next = scl_positives(scl->next);
		return nodo;
	} else {
		return scl_positives(scl->next);
	}
}
