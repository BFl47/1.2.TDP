#include "funzioni.h"

void addSCL(TipoSCL *scl, TipoInfoSCL e) {
    TipoSCL temp = *scl;
    *scl = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    (*scl)->info = e;
    (*scl)->next = temp;
}

void scl_stamp(TipoSCL scl) {
    if (scl == NULL) {
        printf("\n");
        return;
    }
    printf("%f ", scl->info);
    scl_stamp(scl->next);
}

//7.1
int scl_len(TipoSCL scl) {
    if (scl == NULL)
        return 0;
    return 1 + scl_len(scl->next);
}

//7.2
float scl_sum(TipoSCL scl) {
    if (scl == NULL)
        return 0;
    return scl->info + scl_sum(scl->next);
}

//7.3
float scl_media(TipoSCL scl) {
    return media_aux(scl, 0, 0);
}

float media_aux(TipoSCL scl, int i, int somma) {
    if (scl == NULL)
        return somma/i;
    somma += scl->info;
    media_aux(scl->next, i+1, somma);
}

//7.4
float scl_dot(TipoSCL scl1, TipoSCL scl2) {
    if (scl_len(scl1) != scl_len(scl2))
        return -1;
    else if (scl1 == NULL && scl2 == NULL)
        return 0;
    return scl1->info * scl2->info + scl_dot(scl1->next, scl2->next);
}

//7.5
void scl_duplicate_pos(TipoSCL scl, int pos) {
    if (scl == NULL)
        return;
    else if (pos == 0) {
        TipoSCL temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
        temp->info = scl->info;
        temp->next = scl->next;
        scl->next = temp;
    }
    else 
        scl_duplicate_pos(scl->next, pos-1);
}

//7.6
TipoSCL scl_positives(TipoSCL scl) {
    if (scl == NULL)
        return NULL;
    else if (scl->info >= 0) {
        TipoSCL ris = (TipoSCL) malloc(sizeof(TipoNodoSCL));
        ris->info = scl->info;
        ris->next = scl_positives(scl->next);
        return ris;
    }
    else 
        return scl_positives(scl->next);
}

//12.5
int contieneElemento(TipoSCL scl, TipoInfoSCL e) {
    if (scl == NULL)
        return 0;
    else if (scl->info == e)
        return 1;
    return contieneElemento(scl->next, e);
}

//12.6
TipoSCL complemento(TipoSCL scl, TipoSCL elementiDaScartare) {
    if (scl == NULL)
        return NULL;
    else if (!contieneElemento(elementiDaScartare, scl->info)) {
        TipoSCL ris = (TipoSCL) malloc(sizeof(TipoNodoSCL));
        ris->info = scl->info;
        ris->next = complemento(scl->next, elementiDaScartare);
        return ris;
    }
    else
        return complemento(scl->next, elementiDaScartare);
        
}