#include "funzioni.h"

void print(TipoLista l) {
    if (estVuota(l)) {
        printf("\n");
        return;
    }
    printf("%d ", car(l));
    print(cdr(l));
}

//9.1
TipoLista init(T *vec, int len) {
    if (len == 0)
        return listaVuota();
    TipoLista ris = init(vec+1, len-1);
    return cons(*vec, ris);
}

//9.2
TipoLista doubledCopy(TipoLista list) {
    if (estVuota(list))
        return listaVuota();
    TipoLista ris = doubledCopy(cdr(list));
    ris = cons(car(list), ris);
    return cons(car(list), ris);
}

//9.3
TipoLista multipleSublist( TipoLista list, unsigned int m ) {
    if (estVuota(list))
        return listaVuota();
    TipoLista ris = multipleSublist(cdr(list), m);
    if (car(list) % m == 0)
        return cons(car(list), ris);
    return ris;
}

//9.4
TipoLista subList(TipoLista list, int start, int end) {
    return sub_aux(list, start, end, 0);
}

TipoLista sub_aux(TipoLista list, int start, int end, int i) {
    if (estVuota(list) || i == end)
        return listaVuota();
    TipoLista ris = sub_aux(cdr(list), start, end, i+1);
    if (i >= start) 
        return cons(car(list), ris);
    else 
        return ris;
}

//9.5
TipoLista interleave(TipoLista l1, TipoLista l2) {
    return inter_aux(l1, l2, 0);
}

TipoLista inter_aux(TipoLista l1, TipoLista l2, int i) {
    if (estVuota(l2))
        return listaVuota();
    if (i % 2 == 0) {
        return cons(car(l1), inter_aux(cdr(l1), l2, i+1));
    }
    if (i % 2 != 0) {
        return cons(car(l2), inter_aux(l1, cdr(l2), i+1));
    }
}

//12.8
TipoLista inFondo(TipoLista l) {
    if (estVuota(l))
        return listaVuota();
    int primo = car(l);
    return inFondo_aux(primo, cdr(l));
}

TipoLista inFondo_aux(int primo, TipoLista l) {
    if (estVuota(l))
        return cons(primo, listaVuota());
    TipoLista ris = inFondo_aux(primo, cdr(l));
    return cons(car(l), ris);
}

//12.9
TipoLista invertiInParte(TipoLista l, int inizio) {
    if (estVuota(l))
        return listaVuota();
    TipoLista uno = in_ordine(l, inizio);
    
    while (inizio != 0) {
        l = cdr(l);
        inizio--;
    }
    
    l = al_contrario(l, listaVuota());
    
    while (!estVuota(l)) {
        uno = inFondo_aux(car(l), uno);
        l = cdr(l);
    }
    
    return uno;
    
}

TipoLista in_ordine(TipoLista l, int inizio) {
    if (estVuota(l) || inizio == 0)
        return listaVuota();
    TipoLista ris = in_ordine(cdr(l), inizio-1);
    return cons(car(l), ris);
}

TipoLista al_contrario(TipoLista l, TipoLista ris) {
    if (estVuota(l))
        return ris;
    ris = cons(car(l), ris);
    return al_contrario(cdr(l), ris);
}