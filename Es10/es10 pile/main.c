#include "funzioni.h"

int main() {
    printf("funzione 10.1\n");
    //stampa_sequenza_inversa();
    
    printf("funzione 10.2\n");
    Pila* p = pilaVuota();
    inPila(p, 1); inPila(p, 2); inPila(p, 3); inPila(p, 4);
    printPila(p);
    int v[] = {4, 1, 3};
    rimuovi_alcuni(p, v, 3);
    printPila(p);
    /*
    printf("funzione 10.3\n");
    char* s = "12344521";
    bool pal = check_palindrome(s);
    if (pal) printf("true\n");
    else printf("false\n");
    */
    printf("funzione 10.5\n");
    int v1[] = {1, 3, 4, 2, 4, 2, 3};
    int* v2 = rimuoviMinori(v1, 7);
    

    return 0;
}
