#include "funzioni.h"

//10.6
void stampa_sequenza(void) {
    int elem;
    Coda* c = codaVuota();
    do {
        scanf("%d", &elem);
        if (elem >= 0)
            inCoda(c, elem);
    } while (elem >= 0);
    
    while (!estCodaVuota(c)) 
        printf("%d ", outCoda(c));
    printf("\n");
}

//10.7
int elemento_iesimo(Coda *c, int pos) {
    if (estCodaVuota(c))
        return -1;
    else if (pos == 0)
        return outCoda(c);
    else {
        outCoda(c);
        return elemento_iesimo(c, pos-1);
    }
}

//10.8
void avoid_stampa(Coda *c, int elem) {
    Coda* temp = codaVuota();
    printf("{ ");
    while (!estCodaVuota(c)) {
        int corrente = outCoda(c);
        inCoda(temp, corrente);
        if (corrente != elem)
            printf("%d ", corrente);
    }
    printf("}\n");
    while (!estCodaVuota(temp)) {
        elem = outCoda(temp);
        inCoda(c, elem);
    }
}

//10.9
Coda * coda_circolare(Coda *c, int n) {
    Coda* ris = codaVuota();
    while (n != 0) {
        int elem = outCoda(c);
        inCoda(ris, elem);
        inCoda(c, elem);
        n--;
    }
    return ris;
}

//10.10
Coda * elementi_pari(Coda *c) {
    Coda* ris = codaVuota();
    int i = 0;
    while (!estCodaVuota(c)) {
        int elem = outCoda(c);
        if (i % 2 == 0) 
            inCoda(ris, elem);
        i++;
    }
    return ris;
}