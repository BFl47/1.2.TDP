
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "alberi_funz.h"
#include "liste_funz.h"
#include "mat.h"
#include "sol1.h"

TipoLista createRandomList(int size, int max_value);


int main(void) {

    // Creo
    const char s1[] = "(7(1()(1()()))(4()()))";
    TipoAlbero a1 = da_stringa(s1);
    const char s2[] = "(5()(1()(1()())))";
    TipoAlbero a2 = da_stringa(s2);
    const char s3[] = "(1(1(2()())(3()()))(2()()))";
    TipoAlbero a3 = da_stringa(s3);
    const char s4[] = "(10(5(2()())(6()()))(12()()))";
    TipoAlbero a4 = da_stringa(s4);
    
    //singleChildSum
    printf("------------------------------------------\nCheck singleChildSum:\n------------------------------------------\n\n");
    printf("Albero input:\n");
    stampa_albero(a1);
    int sol = singleChildSum(a1);
    printf("singleChildSum, soluzione %d\n\n\n\n", sol);

    printf("Albero input:\n");
    stampa_albero(a2);
    sol = singleChildSum(a2);
    printf("singleChildSum, soluzione %d\n\n\n\n", sol);

    printf("Albero input:\n");
    stampa_albero(a3);
    sol = singleChildSum(a3);
    printf("singleChildSum, soluzione %d\n\n\n\n", sol);

    printf("Albero input:\n");
    stampa_albero(a4);
    sol = singleChildSum(a4);
    printf("singleChildSum, soluzione %d\n\n\n\n", sol);


    //livelliCompleti
    printf("------------------------------------------\nCheck livelliCompleti:\n------------------------------------------\n\n");
    printf("Albero input:\n");
    stampa_albero(a1);
    printf("\n");
    int res = livelliCompleti(a1);
    printf("Risultato: %d\n\n\n\n", res);

    printf("Albero input:\n");
    stampa_albero(a2);
    printf("\n");
    res = livelliCompleti(a2);
    printf("Risultato: %d\n\n\n\n", res);

    printf("Albero input:\n");
    stampa_albero(a3);
    printf("\n");
    res = livelliCompleti(a3);
    printf("Risultato: %d\n\n\n\n", res);

    printf("Albero input:\n");
    stampa_albero(a4);
    printf("\n");
    res = livelliCompleti(a4);
    printf("Risultato: %d\n\n\n\n", res);


    //lista_nodi_foglia
    printf("------------------------------------------\nCheck lista_nodi_foglia:\n------------------------------------------\n\n");
    printf("Albero input:\n");
    stampa_albero(a1);
    TipoLista lista_nodi_foglia = listaNodiFoglia(a1);
    printf("listaNodiFoglia, soluzione: ");
    printlist(lista_nodi_foglia);
    printf("\n\n");

    printf("Albero input:\n");
    stampa_albero(a2);
    lista_nodi_foglia = listaNodiFoglia(a2);
    printf("listaNodiFoglia, soluzione: ");
    printlist(lista_nodi_foglia);
    printf("\n\n");

    printf("Albero input:\n");
    stampa_albero(a3);
    lista_nodi_foglia = listaNodiFoglia(a3);
    printf("listaNodiFoglia, soluzione: ");
    printlist(lista_nodi_foglia);
    printf("\n\n");

    printf("Albero input:\n");
    stampa_albero(a4);
    lista_nodi_foglia = listaNodiFoglia(a4);
    printf("listaNodiFoglia, soluzione: ");
    printlist(lista_nodi_foglia);
    printf("\n\n");
    

    //taglia_livello
    printf("------------------------------------------\nCheck taglia_livello:\n------------------------------------------\n\n");
    printf("Albero input:\n");
    stampa_albero(a1);
    TipoAlbero albero_tagliato = taglia_livello(a1, 1);
    printf("Albero risultato:\n");
    stampa_albero(albero_tagliato);
    printf("\n\n\n\n");

    printf("Albero input:\n");
    stampa_albero(a2);
    albero_tagliato = taglia_livello(a2, 1);
    printf("Albero risultato:\n");
    stampa_albero(albero_tagliato);
    printf("\n\n\n\n");

    printf("Albero input:\n");
    stampa_albero(a3);
    albero_tagliato = taglia_livello(a3, 1);
    printf("Albero risultato:\n");
    stampa_albero(albero_tagliato);
    printf("\n\n\n\n");

    printf("Albero input:\n");
    stampa_albero(a4);
    albero_tagliato = taglia_livello(a4, 1);
    printf("Albero risultato:\n");
    stampa_albero(albero_tagliato);
    printf("\n\n\n\n");


		puts("Lists");
		srand(15831);
		TipoLista l1 = createRandomList(5, 5);
		TipoLista l2 = createRandomList(5, 5);
		TipoLista l3 = createRandomList(5, 5);

		puts("Inverti in parte from 2");
		printlist(l1);
		printlist(invertiInParte(l1, 2));
		printlist(l2);
		printlist(invertiInParte(l2, 2));
		printlist(l3);
		printlist(invertiInParte(l3, 2));


		puts("In fondo");
		printlist(l1);
		printlist(inFondo(l1));
		printlist(l2);
		printlist(inFondo(l2));
		printlist(l3);
		printlist(inFondo(l3));


		puts("complemento from l1 and l1, l1 and l2, l1 and l3");
		printlist(complemento(l1, l1));
		printlist(complemento(l1, l2));
		printlist(complemento(l1, l3));

		puts("Alcuni test mancano, vedi next_step, e conditionalSum");
		puts("Tuttavia le soluzioni sono presenti, e i test sono facili da scrivere");
}


TipoLista createRandomList(int size, int max_value)
{
  TipoLista random_list = listaVuota();
  for (int i = 0; i < size; ++i)
    random_list = cons(rand() % max_value, random_list);
  return random_list;
}

