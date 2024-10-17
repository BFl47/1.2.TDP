#include "pila.h"

int main() {
    Pila* p = pilaVuota();
    bool val0 = estVuota(p);
    if (!val0) printf("Pila non vuota\n");
    else printf("Pila vuota\n");
    
    push(p, 7);
    bool val1 = estVuota(p);
    if (!val1) printf("Pila non vuota\n");
    else printf("Pila vuota\n");
    
    push(p, 8);
    T val = top(p);
    printf("Top: %d\n", val);
    
    pop(p);
    val = top(p);
    printf("Top: %d\n", val);
    bool val2 = estVuota(p);
    if (!val2) printf("Pila non vuota\n");
    else printf("Pila vuota\n");
    
   
   
   
   
    return 0;
}
