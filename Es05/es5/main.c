#include "funzioni.h"

int main()
{
    printf("funzione 5.1\n");
    Mat* m = mat_alloc(2, 3);
    
    printf("funzione 5.3\n");
    mat_rand(m);
    mat_print(m);
    
    printf("funzione 5.4\n");
    Mat* m1 = mat_clone(m);
    mat_print(m1);
    
    printf("funzione 5.5\n");
    Mat* m2 = mat_alloc(3, 2);
    mat_rand(m2);
    //mat_scan(m2);
    mat_print(m2);
    bool b = mat_is_symmetric(m);
    if (b) printf("true\n");
    else printf("false\n");
    
    printf("funzione 5.6\n");
    mat_normalize_rows(m);
    mat_print(m);
    
    printf("funzione 5.7\n");
    Mat* m3 = mat_sum(m, m1);
    mat_print(m3);
    
    printf("funzione 5.8\n");
    Mat* m4 = mat_product(m1, m2);
    mat_print(m4);
    
    printf("funzione 5.10\n");
    char* array[] = {
        "44 gatti",
        "in",
        "fila per 6",
        "con il resto di 2",
        NULL
    };
    
    sort_strings(array);
    int i = 0;
    while (array[i] != NULL) {
        printf("%s\n", array[i]);
        i++;
    }
    
    

    
    
    
    printf("funzione 5.2\n");
    mat_free(m); mat_free(m1); mat_free(m2);
    mat_free(m3);

    return 0;
}
