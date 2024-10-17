#include "funzioni.h"

int main() {
    printf("funzione 7.7\n");
    TipoSCL scl = NULL;
    addSCL(&scl, 'o'); addSCL(&scl, 't'); addSCL(&scl, 't'); addSCL(&scl, 'a'); addSCL(&scl, 'G'); 
    scl_stamp(scl);
    
    printf("funzione 7.8\n");
    char* s = "Gattoso";
    TipoSCL scl1 = sclstring_create(s);
    scl_stamp(scl1);
    
    printf("funzione 7.9\n");
    bool b = sclstring_equals(scl, s);
    if (b) printf("true\n");
    else printf("false\n");
    
    printf("funzione 7.10\n");
    sclstring_remove(&scl, 't');
    scl_stamp(scl);

    return 0;
}
