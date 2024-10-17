#include "funzioni.h"

int main() {
    
    printf("funzione 8.1\n");
    int v[] = {1, 2, 3, 4};
    Insieme i = init(v, 4);
    
    printf("funzione 8.2\n");
    print(i);
    
    printf("funzione 8.3\n");
    Insieme i1 = copy(i);
    print(i1);
    
    printf("funzione 8.4\n");
    int e = size(i);
    printf("%d\n", e);
    
    printf("funzione 8.5\n");
    int v1[] = {1, 4, 7};
    Insieme i2 = init(v1, 3);
    int b = subset(i2, i);
    if (b) printf("true\n");
    else printf("false\n");
    
    printf("funzione 8.6\n");
    b = equal(i1, i);
    if (b) printf("true\n");
    else printf("false\n");
    
    printf("funzione 8.7\n");
    Insieme i3 = intersection(i, i2);
    //print(i); print(i2);
    print(i3);
    
    printf("funzione 8.8\n");
    Insieme i4 = un(i, i2);
    print(i4);
    
    
    return 0;
}
