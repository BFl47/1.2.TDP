#include "funzioni.h"

int main() {
    printf("funzione 5.11\n");
    
    Mat* m = mat_read("prova.txt");
    mat_print(m);
    
    printf("funzione 5.12\n");
    mat_write("prova1.txt", m);

    return 0;
}
