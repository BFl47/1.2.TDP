
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "alberi_funz.h"
#include "liste_funz.h"
#include "mat.h"


bool hasOneChild(TipoAlbero a) {
	return estVuoto(sinistro(a)) != estVuoto(destro(a));
}


int singleChildSum(TipoAlbero a) {
	if (estVuoto(a)) {
		return 0;
	}
	int sum = 0;
	sum += singleChildSum(sinistro(a));
	sum += singleChildSum(destro(a));
	if (hasOneChild(a)) {
		sum += radice(a);
	}
	return sum;
}


int livelliCompleti(TipoAlbero a) {
	if (estVuoto(a)) {
		return -1;
	}
	if (hasOneChild(a)) {
		return 0;
	}
	int leftLevel = livelliCompleti(sinistro(a));
	int rightLevel = livelliCompleti(destro(a));
	int level = (leftLevel > rightLevel) ? rightLevel : leftLevel;
	return level + 1;
}


TipoLista listaNodiFogliaAux(TipoAlbero a, TipoLista acc) {
	if (estVuoto(a)) {
		return acc;
	}
	if (estVuoto(sinistro(a)) && estVuoto(destro(a))) {
		return cons(radice(a), acc);
	}
	acc = listaNodiFogliaAux(destro(a), acc);
	acc = listaNodiFogliaAux(sinistro(a), acc);
	return acc;
}

TipoLista listaNodiFoglia(TipoAlbero a) {
	return listaNodiFogliaAux(a, listaVuota());
}


TipoInfoAlbero sum_all(TipoAlbero a) {
	if (estVuoto(a)) {
		return 0;
	}
	
	int sum = 0;
	sum += sum_all(sinistro(a));
	sum += sum_all(destro(a));

	return sum + radice(a);
}


TipoAlbero taglia_livello(TipoAlbero a, int livello) {

	if (estVuoto(a)) {
		return albBinVuoto();
	}

	if (livello == 0) {
		TipoInfoAlbero sum = sum_all(a);
		return creaAlbBin(sum, albBinVuoto(), albBinVuoto());
	}
	else {
		TipoAlbero sx = taglia_livello(sinistro(a), livello -1);
		TipoAlbero dx = taglia_livello(destro(a), livello -1);
		return creaAlbBin(radice(a), sx, dx);
	}
}


int conditionalSum(const FloatMat *m, int flag) {
	float res=0;
	for (int r = 0; r < m->rows; ++r) {
		for (int c = 0; c < m->cols; ++c) {
			
			if (flag==0){
				if (c%2!=0){
					res-=m->mat[r][c];
				}else{
					res+=m->mat[r][c];
				}
			}
			else{
				if (r%2!=0){
					res-=m->mat[r][c];
				}else{
					res+=m->mat[r][c];
				}
			}
		}
	}
	return res;
}


int contieneElemento(TipoSCL l, TipoInfoSCL e) {
  if(l == NULL)  return 0;
  if(l->info == e)  return 1;
  return contieneElemento(l->next, e);
}


TipoSCL appendSCL(TipoSCL l, TipoInfoSCL e) {
	if (l == NULL) {
		TipoNodo *nuovo = (TipoNodo *)malloc(sizeof(TipoNodo));
		nuovo->info = e;
		nuovo->next = NULL;
		return nuovo;
	}
	if (l->next == NULL) {
		TipoNodo *nuovo = (TipoNodo *)malloc(sizeof(TipoNodo));
		nuovo->info = e;
		nuovo->next = NULL;
		l->next = nuovo;
		return l;
	}

	return appendSCL(l->next, e);
}


TipoSCL complemento(TipoSCL scl, TipoSCL elementiDaScartare) {
  if(scl == NULL)  return NULL;
  
  TipoSCL iterator = scl;
	TipoSCL output = NULL;

  while (iterator) { 
    TipoInfoSCL e = iterator->info;
    if(!contieneElemento(elementiDaScartare, e)) {
			output = appendSCL(output, e);
		}
    iterator = iterator->next;
  }
  return output;
}


int next_step(CharMat *m, char direction) {

	// Search the snake
	int r, c;
	bool head_found = false;
	for (int i = 0; i < m->rows && !head_found; ++i) {
		for (int j = 0; j < m->cols && !head_found; ++j) {
			if (m->mat[i][j] == HEAD) {
				r = i;
				c = j;
				head_found = true;
			}
		}
	}
	
	// Move it
	m->mat[r][c] = ' ';
	switch (direction) {
		case UP:
			--r;
			break;
		case LEFT:
			--c;
			break;
		case RIGHT:
			++c;
			break;
		case DOWN:
			++r;
			break;
	}

	// Points
	int ret = 0;
	if (m->mat[r][c] == APPLE) {
		ret = 1;
	} else if (m->mat[r][c] == BORDER) {
		ret = -1;
	}

	m->mat[r][c] = 'X';
	return ret;
}


TipoLista inFondo_aux(TipoLista l, TipoInfoSCL to_add) {

  if (estVuota(l)) {
    return cons(to_add, listaVuota());
  }

  return cons(car(l), inFondo_aux(cdr(l), to_add));
}


TipoLista inFondo(TipoLista l) {

  if (estVuota(l))
    return listaVuota();

  TipoInfoSCL first = car(l);
  l = cdr(l);

  return inFondo_aux(l, first);
}


TipoLista invertiInParte(TipoLista l, int inizio) {
	if (estVuota(l)) {
		return listaVuota();
	}

	// Copio solamente
	if (inizio > 0) {
		TipoLista coda = invertiInParte(cdr(l), inizio - 1);
		return cons(car(l), coda);
	}

	// Inverto
	else {
		TipoLista l2 = invertiInParte(cdr(l), inizio - 1);
		TipoLista l3 = inFondo(cons(car(l), l2));
		return l3;
	}
}
