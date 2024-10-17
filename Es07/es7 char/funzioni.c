#include "funzioni.h"

void addSCL(TipoSCL *scl, TipoInfoSCL e) {
    TipoSCL temp = *scl;
    *scl = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    (*scl)->info = e;
    (*scl)->next = temp;
}

//7.7
void scl_stamp(TipoSCL scl) {
    if (scl == NULL) {
        printf("\n");
        return;
    }
    printf("%c ", scl->info);
    scl_stamp(scl->next);
}

//7.8
TipoSCL sclstring_create(const char *s) {
    if (*s == '\0')
        return NULL;
    TipoSCL ris = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    ris->info = *s;
    ris->next = sclstring_create(s+1);
    return ris;
}

//7.9
bool sclstring_equals(TipoSCL scl, const char *s) {
    if (scl == NULL && *s == '\0')
        return true;
    else if (scl == NULL && *s != '\0' || scl != NULL && *s == '\0')
        return false;
    else if (scl->info == *s)
        return true && sclstring_equals(scl->next, s+1);
    return false;
}

//7.10
void sclstring_remove(TipoSCL *scl_p, char val) {
    if (*scl_p == NULL)
        return;
    else if ((*scl_p)->info == val) {
        TipoSCL temp = *scl_p;
        *scl_p = (*scl_p)->next;
        free(temp);
        sclstring_remove(&(*scl_p), val);
    }
    else
        sclstring_remove(&((*scl_p)->next), val);
    
}