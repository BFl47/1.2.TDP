#include "funzioni.h"

int main() {
   
    printf("funzione 9.1\n");
    int v[] = {1, 2, 3, 4};
    TipoLista l = init(v, 4);
    print(l);
    
    printf("funzione 9.2\n");
    TipoLista l1 = doubledCopy(l);
    print(l1);
    
    printf("funzione 9.3\n");
    TipoLista l2 = multipleSublist(l1, 2);
    print(l2);
    
    printf("funzione 9.4\n");
    TipoLista l3 = subList(l1, 1, 4);
    print(l3);
    
    printf("funzione 9.5\n");
    TipoLista l4 = interleave(l, l2); //1 2 2 2 3 4 4 4
    print(l4);
    
    printf("funzione 12.8\n");
    int v1[] = {1, 2, 3, 4, 5, 6};
    TipoLista l5 = init(v1, 6);
    TipoLista l6 = inFondo(l5);
    print(l6);
    
    printf("funzione 12.9\n");
    TipoLista l7 = invertiInParte(l5, 3);
    print(l7);
    
    
    
    return 0;
}
