#pragma once

#include "lista.h"
//put signature here

TipoLista init(T *vec, int len);
TipoLista doubledCopy(TipoLista list);
TipoLista multipleSubset(TipoLista list, unsigned int m);
TipoLista newNode(T info);

TipoLista subList(TipoLista Lista, int start, int end);
TipoLista interleave(TipoLista l1, TipoLista l2);
TipoLista reduce_mul(TipoLista l);
