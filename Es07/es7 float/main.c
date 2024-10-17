#include "funzioni.h"

int main() {
    
    printf("funzione 7.1\n");
    TipoSCL scl = NULL;
    addSCL(&scl, 3); addSCL(&scl, 2); addSCL(&scl, 1); 
    scl_stamp(scl);
    int e = scl_len(scl);
    printf("%d\n", e);
    
    printf("funzione 7.2\n");
    float e1 = scl_sum(scl);
    printf("%f\n", e1);
    
    printf("funzione 7.3\n");
    float e2 = scl_media(scl);
    printf("%f\n", e2);
    
    printf("funzione 7.4\n");
    TipoSCL scl1 = NULL;
    addSCL(&scl1, 1); addSCL(&scl1, -4); addSCL(&scl1, 2); addSCL(&scl1, -3);
    float e3 = scl_dot(scl, scl1);
    printf("%f\n", e3);
    
    printf("funzione 7.5\n");
    scl_duplicate_pos(scl, 1);
    scl_stamp(scl);
    
    printf("funzione 7.6\n");
    scl_stamp(scl1);
    TipoSCL scl2 = scl_positives(scl1);
    scl_stamp(scl2);
    
    printf("funzione 12.5\n");
    int e4 = contieneElemento(scl, 17);
    if (e4) printf("true\n");
    else printf("false\n");
    
    printf("funzione 12.6\n");
    //3 -> 8 -> 8 -> 2 -> 7 -> 0 -> 11 -> 2
    TipoSCL scl3 = NULL;
    addSCL(&scl3, 2); addSCL(&scl3, 11); addSCL(&scl3, 0); addSCL(&scl3, 7);
    addSCL(&scl3, 2); addSCL(&scl3, 8); addSCL(&scl3, 8); addSCL(&scl3, 3);
    scl_stamp(scl3);
    // 8 -> 7 -> 11
    TipoSCL scl4 = NULL;
    addSCL(&scl4, 7); addSCL(&scl4, 8); addSCL(&scl4, 11);
    scl_stamp(scl4);
    
    TipoSCL scl5 = complemento(scl3, scl4);
    scl_stamp(scl5);
    
    return 0;
}
