#include <stdio.h>
#include <stdlib.h>

#include "alberi_funz.h"

// Implementazioni del tipo astratto
//
// Valore di errore
TipoInfoAlbero ERRORE_InfoAlbBin='*';

TipoAlbero albBinVuoto() {
  return NULL;
}

TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx) {
  TipoAlbero a = (TipoAlbero) malloc(sizeof(TipoNodoAlbero));
  a->info = info;
  a->sinistro = sx;
  a->destro = dx;
  return a;
}


bool estVuoto(TipoAlbero a) {
  return (a == NULL);
}

TipoInfoAlbero radice(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return ERRORE_InfoAlbBin;
  } else {
    return a->info;
  }
}


TipoAlbero sinistro(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } else {
    return a->sinistro;
  }
}

TipoAlbero destro(TipoAlbero a) {
  if (a == NULL) {
    printf ("ERRORE accesso albero vuoto \n");
    return NULL;
  } else {
    return a->destro;
  }
}


// Funzioni esterne

void stampaParentetica(TipoAlbero a) {
    if (estVuoto(a)) {
        printf("()");
    }
    else {
        printf("( %c ", radice(a));
        stampaParentetica(sinistro(a));
        printf(" ");
        stampaParentetica(destro(a));
        printf(" )");
    }
}


// Lettura formato stringa parentetica (no spazi)
TipoAlbero da_stringa_aux(const char *s, int *cursore)
{

	// Inizio albero
	if (s[(*cursore)++] != '(')
	{
		fprintf(stderr, "Errore stringa parentetica\n");
		exit(1);
	}

	// Se vuoto
	if (s[*cursore] == ')')
	{
		++(*cursore);
		return albBinVuoto();
	}

	// Leggi valore
	int info;
	int read_chars;
	sscanf(s + *cursore, "%d%n", &info, &read_chars);
	*cursore += read_chars;

	// Leggi sottoalberi
	TipoAlbero left = da_stringa_aux(s, cursore);
	TipoAlbero right = da_stringa_aux(s, cursore);

	// Fine albero
	if (s[(*cursore)++] != ')')
	{
		fprintf(stderr, "Errore stringa parentetica\n");
		exit(1);
	}

	return creaAlbBin(info, left, right);
}

TipoAlbero da_stringa(const char *s)
{
	int cursore = 0;
	return da_stringa_aux(s, &cursore);
}


void stampa_albero_aux(TipoAlbero a, int livello)
{
	for (int i = 0; i < livello; ++i)
		putchar(' ');
	putchar('-');

	if (estVuoto(a))
	{
		puts("");
		return;
	}
	printf(" %d\n", radice(a));
	stampa_albero_aux(sinistro(a), livello + 1);
	stampa_albero_aux(destro(a), livello + 1);
}

void stampa_albero(TipoAlbero a) {
	stampa_albero_aux(a, 0);
	puts("");
}
