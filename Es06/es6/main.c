#include "funzioni.h"

int main() {
    
    printf("funzione 6.1\n");
    float v[] = {1, 2, 3, 4};
    float elem = product(v, 4);
    printf("%f\n", elem);
    
    printf("funzione 6.2\n");
    vec_integral(v, 4);
    vec_print(v, 4);
    
    printf("funzione 6.3\n");
    char s[] = "Gattoso";
    int elem1 = length(s);
    printf("%d\n", elem1);
    
    printf("funzione 6.4\n");
    int elem2 = char_position(s, 'o');
    printf("%d\n", elem2);
    
    printf("funzione 6.5\n");
    bool b = is_lowercase(s);
    if (b) printf("true\n");
    else printf("false\n");
    
    printf("funzione 6.6\n");
    to_uppercase(s);
    printf("%s\n", s);
    
    printf("funzione 6.7\n");
    char s1[] = "attoGatto";
    //copy(s1, s);
    
    printf("funzione 6.8\n");
    concat(s, s1);
    printf("%s\n", s);
    
    printf("funzione 6.8\n");
    char s2[] = "GattoSsIsImaMente gaTTo";
    FILE* f = fopen("prova.txt", "w");
    filter_write(s2, f);
    fclose(f);
    
    printf("funzione 6.9\n");
    FILE* f1 = fopen("prova.txt", "r");
    FILE* f2 = fopen("provaprova.txt", "r");
    bool b1 = same_content(f1, f2);
    if (b1) printf("true\n");
    else printf("false\n");
    
    fclose(f1); fclose(f2);

    return 0;
}
