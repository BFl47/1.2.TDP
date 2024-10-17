#include "funzioni.h"

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

bool estFoglia(TipoAlbero a) {
    if (estVuoto(a))
        return false;
    if (estVuoto(sinistro(a)) && estVuoto(destro(a)))
        return true;
    return false;
}

//11.1
TipoInfoAlbero trova_massimo(TipoAlbero a) {
    if (estVuoto(a))
        return -1;
    int sx = max(radice(a), trova_massimo(sinistro(a)));
    int dx = max(radice(a), trova_massimo(destro(a)));
    return max(sx, dx);
}

//11.2
TipoInfoAlbero somma_foglie(TipoAlbero a) {
    if (estVuoto(a))
        return 0;
    else if (estFoglia(a))
        return radice(a);
    return somma_foglie(sinistro(a)) + somma_foglie(destro(a));
}

//11.3
int cerca_livello(TipoAlbero a, TipoInfoAlbero v) {
    return cerca_livello_aux(a, v, 0);
}

int cerca_livello_aux(TipoAlbero a, TipoInfoAlbero v, int lv) {
    if (estVuoto(a))
        return -1;
    else if (radice(a) == v)
        return lv;
    int sx = cerca_livello_aux(sinistro(a), v, lv+1);
    int dx = cerca_livello_aux(destro(a), v, lv+1);
    if (sx >= dx) return sx;
    return dx;
}

//11.4
int conta_dispari(TipoAlbero a) {
    if (estVuoto(a))
        return 0;
    if (somma(a) % 2 != 0)
        return 1 + conta_dispari(sinistro(a)) + conta_dispari(destro(a));
    else
        return conta_dispari(sinistro(a)) + conta_dispari(destro(a));
}

int somma(TipoAlbero a) {
    if (estFoglia(a))
        return radice(a);
    else if (un_successore(a) && !estVuoto(sinistro(a)))
        return radice(a) + radice(sinistro(a));
    else if (un_successore(a) && !estVuoto(destro(a)))
        return radice(a) + radice(destro(a));
    else
        return radice(a) + radice(destro(a)) + radice(sinistro(a));
}

bool un_successore(TipoAlbero a) {
    if (estVuoto(a) || estFoglia(a))
        return false;
    else if (!estVuoto(sinistro(a)) && estVuoto(destro(a)) ||
            estVuoto(sinistro(a)) && !estVuoto(destro(a)))
        return true;
    else 
        return false;
}

//11.5
int somma_singoli(TipoAlbero a) {
    if (estVuoto(a) || estFoglia(a))
        return 0;
    else if (un_successore(a))
        return radice(a) + somma_singoli(sinistro(a)) + somma_singoli(destro(a));
    else
        return somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}

//11.6
TipoLista albero_lista(TipoAlbero a, TipoLista ris) {
    if (estVuoto(a))
        return ris;
    ris = albero_lista(sinistro(a), ris);
    ris = cons(radice(a), ris);
    ris = albero_lista(destro(a), ris);
    return ris;
}

//11.7
TipoLista percorso_lungo(TipoAlbero a) {
    if (estVuoto(a))
        return listaVuota();
    else if (estFoglia(a))
        return cons(radice(a), listaVuota());
    TipoLista sx = cons(radice(a), percorso_lungo(sinistro(a)));
    TipoLista dx = cons(radice(a), percorso_lungo(destro(a)));
    if (len(sx) >= len(dx))
        return sx;
    return dx;
}

//11.8
TipoAlbero somma_sottoalbero(TipoAlbero a) {
    if (estVuoto(a))
        return albBinVuoto();
    else if (estFoglia(a))
        return creaAlbBin(radice(a), albBinVuoto(), albBinVuoto());
    else
        return creaAlbBin(somma(a) - radice(a), somma_sottoalbero(sinistro(a)), somma_sottoalbero(destro(a)));
}

//11.9
TipoAlbero scambia_foglie(TipoAlbero a) {
    if (estVuoto(a))
        return albBinVuoto();
    
    else if ( estFoglia(sinistro(a)) && estFoglia(destro(a)) )
        return creaAlbBin(radice(a), destro(a), sinistro(a));
        
    return creaAlbBin(radice(a), scambia_foglie(sinistro(a)), scambia_foglie(destro(a)));
}

//12.2
int livelli_completi(TipoAlbero a) {
    int* array = (int*) calloc(10, sizeof(int));
    liv_aux(a, array);
    int pos;
    for (int i = 0; i < 10; i++) {
        if (array[i] == pow(2, i))
            pos = i;
    }
    return pos;
}

void liv_aux(TipoAlbero a, int* array) {
    if (estVuoto(a))
        return;
    *array += 1;
    liv_aux(sinistro(a), array+1);
    liv_aux(destro(a), array+1);
}

//12.1
int singleChildSum(TipoAlbero a) {
    if (estVuoto(a) || estFoglia(a))
        return 0;
    else if (un_successore(a))
        return radice(a);
    return singleChildSum(sinistro(a)) + singleChildSum(destro(a));
}

//12.3
TipoLista listaNodiFoglia(TipoAlbero a, TipoLista ris) {
    if (estVuoto(a))
        return ris;
    else if (estFoglia(a))
        return cons(radice(a), ris);
        
    ris = listaNodiFoglia(destro(a), ris);
    ris = listaNodiFoglia(sinistro(a), ris);
    
    return ris;
}

//12.5
TipoAlbero taglia_livello(TipoAlbero a, int livello) {
    if (estVuoto(a) || estFoglia(a))
        return albBinVuoto();
    if (livello == 0)
        return creaAlbBin(somma(a), albBinVuoto(), albBinVuoto());
    TipoAlbero sx = taglia_livello(sinistro(a), livello-1);
    TipoAlbero dx = taglia_livello(destro(a), livello-1);
    return creaAlbBin(radice(a), sx, dx);
    
}