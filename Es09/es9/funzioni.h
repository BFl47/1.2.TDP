#include "lista.h"

void print(TipoLista l);

TipoLista init(T *vec, int len);                                        //9.1
TipoLista doubledCopy(TipoLista list);                                  //9.2
TipoLista multipleSublist( TipoLista list, unsigned int m );            //9.3
TipoLista subList(TipoLista list, int start, int end);                  //9.4
TipoLista sub_aux(TipoLista list, int start, int end, int i); 
TipoLista interleave(TipoLista l1, TipoLista l2);                       //9.5
TipoLista inter_aux(TipoLista l1, TipoLista l2, int i);

TipoLista inFondo(TipoLista l);                             //12.8
TipoLista inFondo_aux(int primo, TipoLista l);
TipoLista invertiInParte(TipoLista l, int inizio);          //12.9
TipoLista in_ordine(TipoLista l, int inizio);
TipoLista al_contrario(TipoLista l, TipoLista ris);