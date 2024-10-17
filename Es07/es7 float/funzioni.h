#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef float TipoInfoSCL;
struct ElemSCL {
TipoInfoSCL info;
struct ElemSCL *next;
};
typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

void addSCL(TipoSCL *scl, TipoInfoSCL e);
void scl_stamp(TipoSCL scl);

int scl_len(TipoSCL scl);                           //7.1
float scl_sum(TipoSCL scl);                         //7.2
float scl_media(TipoSCL scl);                       //7.3
float media_aux(TipoSCL scl, int i, int somma);
float scl_dot(TipoSCL scl1, TipoSCL scl2);          //7.4
void scl_duplicate_pos(TipoSCL scl, int pos);       //7.5
TipoSCL scl_positives(TipoSCL scl);                 //7.6

int contieneElemento(TipoSCL scl, TipoInfoSCL e);                       //12.5
TipoSCL complemento(TipoSCL scl, TipoSCL elementiDaScartare);           //12.6