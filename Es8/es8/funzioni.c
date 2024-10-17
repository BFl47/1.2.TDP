#include "funzioni.h"

//8.1
Insieme init(int *arr, int n) {
    if (n == 0)
        return insiemeVuoto();
    Insieme ris = init(arr+1, n-1);
    ris = inserisci(ris, *arr);
    return ris;
}

//8.2
void print(Insieme s) {
    printf("{ ");
    IteratoreInsieme it = creaIteratoreInsieme(s);
    print_aux(it);
}

void print_aux(IteratoreInsieme it) {
    if (!hasNext(it)) {
        printf("}\n");
        return;
    }
    printf("%d ", next(it));
    print_aux(it);
}

//8.3
Insieme copy(Insieme s) {
    IteratoreInsieme it = creaIteratoreInsieme(s);
    return copy_aux(it);
}

Insieme copy_aux(IteratoreInsieme it) {
    if (!hasNext(it))
        return insiemeVuoto();
    int elem = next(it);
    Insieme ris = copy_aux(it);
    return inserisci(ris, elem);
}

//8.4
int size(Insieme s) {
    return size_aux(creaIteratoreInsieme(s));
}

int size_aux(IteratoreInsieme it) {
    if (!hasNext(it))
        return 0;
    int elem = next(it);
    return 1 + size_aux(it);
}

//8.5
bool subset(Insieme a, Insieme b) {
    IteratoreInsieme it = creaIteratoreInsieme(a);
    return subset_aux(it, b);
}

bool subset_aux(IteratoreInsieme it, Insieme ins) {
    if (!hasNext(it))
        return true;
    int elem = next(it);
    if (membro(ins, elem))
        return true && subset_aux(it, ins);
    return false;
}

//8.6
bool equal(Insieme a, Insieme b) {
    if (subset(a, b) && subset(b, a))
        return true;
    return false;
}

//8.7
Insieme intersection(Insieme a, Insieme b) {
    IteratoreInsieme it = creaIteratoreInsieme(a);
    return iter_aux(it, b);
}

Insieme iter_aux(IteratoreInsieme it, Insieme b) {
    if (!hasNext(it))
        return insiemeVuoto();
    int elem = next(it);
    if (membro(b, elem))
        return inserisci(iter_aux(it, b), elem);
    else 
        return iter_aux(it, b);
}

Insieme un(Insieme a, Insieme b) {
    IteratoreInsieme it = creaIteratoreInsieme(a);
    return un_aux(it, b);
}

Insieme un_aux(IteratoreInsieme it, Insieme ins) {
    if (!hasNext(it))
        return ins;
    int elem = next(it);
    Insieme ris = un_aux(it, ins);
    return inserisci(ris, elem);
}