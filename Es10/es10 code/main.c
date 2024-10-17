#include "funzioni.h"

int main() {
    
    printf("funzione 10.6\n");
    //stampa_sequenza(); 
    
    printf("funzione 10.7\n");
    Coda* c = codaVuota();
    inCoda(c, 1); inCoda(c, 2); inCoda(c, 4); inCoda(c, 3); inCoda(c, 4); 
    printCoda(c);
    
    int elem = elemento_iesimo(c, 1);
    printf("%d\n", elem);
    
    printf("funzione 10.8\n");
    c = codaVuota();
    inCoda(c, 1); inCoda(c, 2); inCoda(c, 4); inCoda(c, 3); inCoda(c, 4);
    printCoda(c);
    avoid_stampa(c, 4);
    
    printf("funzione 10.9\n");
    c = codaVuota();
    inCoda(c, 0); inCoda(c, 1); inCoda(c, 2); inCoda(c, 3);
    Coda* c1 = coda_circolare(c, 10);
    printCoda(c1);
    
    printf("funzione 10.10\n");
    c = codaVuota();
    inCoda(c, 1); inCoda(c, 2); inCoda(c, 4); inCoda(c, 3); inCoda(c, 4);
    Coda* c2 = elementi_pari(c);
    printCoda(c2);
    
    return 0;
}
