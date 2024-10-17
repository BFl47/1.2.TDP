#include "code.h"

int main() {
    Coda *c = codaVuota();
    bool val = estVuota(c);
    if (!val)
        printf("False\n");
    else
        printf("True\n");
        
    inCoda(c, 13);
    bool val1 = estVuota(c);
    if (!val1)                   //False
        printf("False\n");
    else
        printf("True\n");
        
    outCoda(c);
    bool val2 = estVuota(c);
    if (!val2)                   //True
        printf("False\n");
    else
        printf("True\n");
    
    return 0;

}
