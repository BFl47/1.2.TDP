
#include "prova.h"

int main() {
    //Insieme ins = NULL;
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
    
    return 0;
}