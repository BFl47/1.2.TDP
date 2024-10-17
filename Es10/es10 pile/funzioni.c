#include "funzioni.h"

//10.1
void stampa_sequenza_inversa(void) {
    int elem;
    Pila* ris = pilaVuota();
    do {
        scanf("%d", &elem);
        if (elem >= 0)
            inPila(ris, elem);
    } while (elem >= 0);
    
    while (!estPilaVuota(ris))
        printf("%d ", outPila(ris));
    printf("\n");
}

//10.2
void rimuovi_alcuni(Pila *p, const int *rimuovere, int n) {
    if (estPilaVuota(p))
        return;
    else if (inArray(rimuovere, n, primoPila(p))) {
        outPila(p);
        rimuovi_alcuni(p, rimuovere, n);
    }
    else
        return;
    
}

bool inArray(const int* arr, int n, int elem) {
    if (n == 0)
        return false;
    if (*arr == elem)
        return true || inArray(arr+1, n-1, elem);
    else
        return inArray(arr+1, n-1, elem);
}

//10.3
bool check_palindrome(const char* s) {
    int lens = strlen(s);
    if (lens % 2 != 0)
        return false;
    return check_palindrome_aux(s, lens/2);
}

Pila* init(const char* s, int len) {
    Pila* p = pilaVuota();
    while (len > 0) {
        inPila(p, *s);
        s = s+1;
        len--;
    }
    return p;
}
bool check_palindrome_aux(const char* s, int len) {
    Pila* p = init(s, len);
    int temp = len;
    while (temp > 0) {
        s = s+1;
        temp--;
    }
    bool ris = true;
    while (!estPilaVuota(p)) {
        if (*s != outPila(p))
            ris = false;
        s = s+1;
    }
    return ris;
}

//10.5
int* rimuoviMinori(int* arr, int len) {
    Pila* p = pilaVuota();
    int count = 0;
    while (len != 0) {
        
        while (!estPilaVuota(p) && *arr < primoPila(p)) {
            outPila(p);
            count--;
        }
        inPila(p, *arr);
        count++;
        arr = arr+1;
        len--;
    }
    int* ris = (int*) malloc(count * sizeof(int));
    printf("{ ");
    for (int i = 0; i < count; i++) {
        ris[i] = outPila(p);
        printf("%d ", ris[i]);
    }
    printf("}\n");
    return ris;
}