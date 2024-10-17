
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "albero_binario.h"
#include "lista.h"

// Ausiliarie
TipoAlbero da_stringa(const char *s);
void stampa_albero(TipoAlbero a);
bool estFoglia(TipoAlbero a);

// Esercizi
TipoInfoAlbero trova_massimo(TipoAlbero a);
TipoInfoAlbero somma_foglie(TipoAlbero a);
int cerca_livello(TipoAlbero a, TipoInfoAlbero v);
int conta_dispari(TipoAlbero a);
int somma_singoli(TipoAlbero a);
TipoLista albero_lista(TipoAlbero a);
TipoLista percorso_lungo(TipoAlbero a);
void somma_sottoalbero(TipoAlbero a);
void scambia_foglie(TipoAlbero a);


int main(void)
{

	// Creo
	const char s1[] = "(7(1()(1()()))(4()()))";
	TipoAlbero a1 = da_stringa(s1);
	const char s2[] = "(5()(1()(1()())))";
	TipoAlbero a2 = da_stringa(s2);
	const char s3[] = "(1(1(2()())(3()()))(2()()))";
	TipoAlbero a3 = da_stringa(s3);
	const char s4[] = "(10(5(2()())(6()()))(12()()))";
	TipoAlbero a4 = da_stringa(s4);

	// Trova massimo
	puts("\nTest per trova_massimo");
	int m1 = trova_massimo(a1);
	stampa_albero(a1);
	printf(": %d\n", m1);
	int m2 = trova_massimo(sinistro(a1));
	stampa_albero(sinistro(a1));
	printf(": %d\n", m2);
	int m3 = trova_massimo(destro(a1));
	stampa_albero(destro(a1));
	printf(": %d\n", m3);

	// Somma foglie
	puts("\nTest per somma foglie");
	m1 = somma_foglie(a1);
	stampa_albero(a1);
	printf(": %d\n", m1);

	// Cerca livello
	puts("\nTest per cerca_livello");
	int l1 = cerca_livello(a1, 7);
	stampa_albero(a1);
	printf(", valore %d: %d\n", 7, l1);
	int l2 = cerca_livello(a1, 4);
	stampa_albero(a1);
	printf(", valore %d: %d\n", 4, l2);
	int l3 = cerca_livello(a1, 1);
	stampa_albero(a1);
	printf(", valore %d: %d\n", 1, l3);
	int l4 = cerca_livello(a1, 5);
	stampa_albero(a1);
	printf(", valore %d: %d\n", 5, l4);

	// conta_dispari
	puts("\nTest per conta_dispari");
	int ret1 = conta_dispari(a1);
	stampa_albero(a1);
	printf(": %d\n", ret1);
	int ret2 = conta_dispari(sinistro(a1));
	stampa_albero(sinistro(a1));
	printf(": %d\n", ret2);
	int ret3 = conta_dispari(destro(a1));
	stampa_albero(destro(a1));
	printf(": %d\n", ret3);
	int ret4 = conta_dispari(a2);
	stampa_albero(a2);
	printf(": %d\n", ret4);

	// Somma singoli
	puts("\nTest per somma_singoli");
	ret1 = somma_singoli(a1);
	stampa_albero(a1);
	printf(": %d\n", ret1);
	ret2 = somma_singoli(sinistro(a1));
	stampa_albero(sinistro(a1));
	printf(": %d\n", ret2);
	ret3 = somma_singoli(destro(a1));
	stampa_albero(destro(a1));
	printf(": %d\n", ret3);
	ret4 = somma_singoli(a2);
	stampa_albero(a2);
	printf(": %d\n", ret4);

	// Test per albero lista
	puts("\nTest per albero_lista");
	printf("Test da albero binario di ricerca:\n");
	stampa_albero(a4); putchar('\n');
	TipoLista list5 = albero_lista(a4);
	printlist(list5);

	// Percorso lungo
	puts("\nTest per percorso_lungo");
	TipoLista list1 = percorso_lungo(a1);
	stampa_albero(a1);
	printf(": ");
	printlist(list1);
	TipoLista list2 = percorso_lungo(sinistro(a1));
	stampa_albero(sinistro(a1));
	printf(": ");
	printlist(list2);
	TipoLista list3 = percorso_lungo(destro(a1));
	stampa_albero(destro(a1));
	printf(": ");
	printlist(list3);
	TipoLista list4 = percorso_lungo(a2);
	stampa_albero(a2);
	printf(": ");
	printlist(list4);

	// somma_sottoalbero
	puts("\nTest per somma_sottoalbero");
	somma_sottoalbero(a1);
	stampa_albero(a1);
	putchar('\n');
	somma_sottoalbero(a2);
	stampa_albero(a2);
	putchar('\n');
	somma_sottoalbero(a3);
	stampa_albero(a3);
	putchar('\n');

	// Scambia foglie
	puts("\nTest per scambia_foglie");
	scambia_foglie(a1);
	stampa_albero(a1);
	putchar('\n');
	scambia_foglie(a2);
	stampa_albero(a2);
	putchar('\n');
	scambia_foglie(a3);
	stampa_albero(a3);
	putchar('\n');
}

/** Esercizi **/

TipoInfoAlbero trova_massimo(TipoAlbero a)
{
	if (estVuoto(a))
		return -1;

	// Cerca
	int l = trova_massimo(sinistro(a));
	int r = trova_massimo(sinistro(a));

	// Compara
	int max = (l > r) ? l : r;
	max = (radice(a) > max) ? radice(a) : max;
	return max;
}


TipoInfoAlbero somma_foglie(TipoAlbero a)
{
	if (estVuoto(a))
		return 0;

	if (estFoglia(a))
	{
		return radice(a);
	}

	TipoInfoAlbero res = 0;

	res += somma_foglie(sinistro(a));
	res += somma_foglie(destro(a));
	return res;
}

int cerca_livello(TipoAlbero a, TipoInfoAlbero v)
{
	// Casi base
	if (estVuoto(a))
		return -1;
	if (radice(a) == v)
		return 0;

	// Cerca sinistro
	int l = cerca_livello(sinistro(a), v);
	if (l >= 0)
		return l + 1;

	// Cerca destro
	int r = cerca_livello(destro(a), v);
	if (r >= 0)
		return r + 1;

	return -1;
}

int somma_figli(TipoAlbero a)
{
	TipoInfoAlbero res = 0;
	if (estVuoto(a))
		return res;
	res += radice(a);

	res += somma_figli(sinistro(a));
	res += somma_figli(destro(a));

	return res;
}

int conta_dispari(TipoAlbero a)
{
	if (estVuoto(a))
		return 0;

	int res = somma_figli(a);

	if (res % 2 == 0)
	{
		res = 0;
	}
	else
	{
		res = 1;
	}

	res += conta_dispari(sinistro(a));
	res += conta_dispari(destro(a));

	return res;
}

int somma_singoli(TipoAlbero a)
{
	// Foglia
	if (estVuoto(a))
		return 0;

	// Sottoalberi
	int l = somma_singoli(sinistro(a));
	int r = somma_singoli(destro(a));

	// Radice
	if (estVuoto(sinistro(a)) != estVuoto(destro(a)))
	{
		return l + r + 1;
	}
	return l + r;
}

TipoLista albero_lista_aux(TipoAlbero a, TipoLista acc)
{
	// Nulla da aggiungere all'accumulatore
	if (estVuoto(a)) return acc;

	// Visita simmetrica
	acc = albero_lista_aux(sinistro(a), acc);
	acc = cons(radice(a), acc);
	acc = albero_lista_aux(destro(a), acc);

	return acc;
}


TipoLista albero_lista(TipoAlbero a)
{
	return albero_lista_aux(a, listaVuota());
}

int profondita(TipoAlbero a)
{
	if (estVuoto(a))
		return 0;
	int l = profondita(sinistro(a));
	int r = profondita(destro(a));
	return (r > l) ? r + 1 : l + 1;
}

TipoLista percorso_lungo(TipoAlbero a)
{
	// Vuoto
	if (estVuoto(a))
		return listaVuota();

	// Scegli sottoalbero
	int l = profondita(sinistro(a));
	int r = profondita(destro(a));
	TipoAlbero sotto = (r > l) ? destro(a) : sinistro(a);

	// Aggiungi
	TipoLista lista = percorso_lungo(sotto);
	return cons(radice(a), lista);
}

void somma_sottoalbero(TipoAlbero a)
{
	// Nulla da fare
	if (estVuoto(a))
		return;

	if (estFoglia(a))
		return;

	int res=somma_figli(a)-radice(a);
	assegnaRadice(a,res);
	somma_sottoalbero(sinistro(a));
	somma_sottoalbero(destro(a));
	
}

bool estFoglia(TipoAlbero a)
{
	if (estVuoto(a))
		return false;
	if (estVuoto(sinistro(a)) && estVuoto(destro(a)))
		return true;
	return false;
}

void scambia_foglie(TipoAlbero a)
{
	// Nulla da fare
	if (estVuoto(a))
		return;
	if (estFoglia(a))
		return;

	// Genitore di foglie: scambia
	if (estFoglia(sinistro(a)) && estFoglia(destro(a)))
	{
		TipoInfoAlbero temp = radice(sinistro(a));
		assegnaRadice(sinistro(a), radice(destro(a)));
		assegnaRadice(destro(a), temp);
		return;
	}

	scambia_foglie(sinistro(a));
	scambia_foglie(destro(a));
}

/** Ausiliarie **/

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

void stampa_albero(TipoAlbero a)
{
	if (estVuoto(a))
	{
		printf("()");
		return;
	}

	printf("(%d ", radice(a));
	stampa_albero(sinistro(a));
	putchar(' ');
	stampa_albero(destro(a));
	putchar(')');
}
