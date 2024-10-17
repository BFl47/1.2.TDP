
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>



TipoLista init(T *vec, int len)
{
  if (len <= 0) return listaVuota();
	return cons(*vec, init(vec + 1, len - 1));
}


TipoLista doubledCopy(TipoLista list)
{
	if (estVuota(list)) return listaVuota();
	T e = car(list);
	TipoLista tail = cdr(list);
	return cons(e, cons(e, doubledCopy(tail)));
}


TipoLista multipleSubset(TipoLista list, unsigned int m)
{
	if (estVuota(list)) return listaVuota();
	T elem = car(list);
	list = multipleSubset(cdr(list), m);
	if (elem % m == 0)
	{
		return cons(elem, list);
	}
	return list;
}


TipoLista subList(TipoLista list, int start, int end)
{
	if (estVuota(list)) return listaVuota();
	if (start >= end) return listaVuota();

	if (end <= 0) return listaVuota();

	TipoLista tail = subList(cdr(list), start - 1, end - 1);
	if (start <= 0)
		return cons(car(list), tail);
	else
		return tail;
}


TipoLista interleave_aux(TipoLista l1, TipoLista l2, bool even)
{
	if (estVuota(l1) && estVuota(l2)) return listaVuota();

	T elem;
	if (even)
	{
		elem = car(l1);
		l1 = cdr(l1);
	} else
	{
		elem = car(l2);
		l2 = cdr(l2);
	}
	TipoLista tail = interleave_aux(l1, l2, !even);
	return cons(elem, tail);
}


TipoLista interleave(TipoLista l1, TipoLista l2)
{
	return interleave_aux(l1, l2, true);
}
