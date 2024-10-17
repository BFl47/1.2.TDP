#include "coda.h"

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


/* //Insieme ins = NULL;
    Insieme *ins = insiemeVuoto();
    bool val = estVuoto(ins);
    if (!val) printf("False\n");
    else printf("True\n");
    
    inserisci(ins, 10);
    bool val1 = membro(ins, 10);
    if (!val1) printf("False\n");       //Vero
    else printf("True\n");
    
    elimina(ins, 10);
    bool val2 = membro(ins, 10);
    if (!val2) printf("False\n");       //Falso
    else printf("True\n");
    
    return 0; */