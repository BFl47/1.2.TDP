#include "pile.h"

int main() {
    Pila* p = pilaVuota();
    bool val = estVuota(p);
    if (!val) printf("Pila non vuota\n");
    else printf("Pila vuota\n");           //
    
    pushPila(p, 7);
    bool val1 = estVuota(p);
    if (!val1) printf("Pila non vuota\n"); //
    else printf("Pila vuota\n");
    pushPila(p, 8);
    T first0 = topPila(p);
    printf("%d\n", first0);
    
    popPila(p);
    bool val2 = estVuota(p);
    if (!val2) printf("Pila non vuota\n"); 
    else printf("Pila vuota\n");            //
    
    T first1 = topPila(p);
    printf("%d\n", first1);
    
    return 0;
}