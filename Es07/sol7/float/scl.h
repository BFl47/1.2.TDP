
#pragma once

typedef float TipoInfoSCL;

struct ElemSCL {
	TipoInfoSCL info ;
	struct ElemSCL * next ;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;


// esercizi
int scl_len(TipoSCL scl); 
float scl_sum(TipoSCL scl); 
float scl_media(TipoSCL scl); 
float scl_dot(TipoSCL scl1, TipoSCL scl2);
void scl_duplicate_pos(TipoSCL scl, int pos);
TipoSCL scl_positives(TipoSCL scl); 


// Ausiliarie
TipoSCL listPushFront(TipoSCL p0, int info);
TipoSCL listPushBack(TipoSCL l, int info);
TipoSCL copyList(TipoSCL list);
TipoSCL createRandomList(int size);
bool equalLists(TipoSCL l1, TipoSCL l2);
void freeList(TipoSCL list);
void printList(TipoSCL l);
