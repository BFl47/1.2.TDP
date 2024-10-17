#include "funzioni.h"

int main() {
    
    printf("funzione 11.1\n");
    TipoAlbero a = creaAlbBin(7, albBinVuoto(), albBinVuoto());
    TipoAlbero b = creaAlbBin(2, albBinVuoto(), albBinVuoto());
    TipoAlbero c = creaAlbBin(3, albBinVuoto(), albBinVuoto());
    TipoAlbero d = creaAlbBin(11, albBinVuoto(), a);
    TipoAlbero e = creaAlbBin(5, b, c);
    TipoAlbero f = creaAlbBin(9, d, e);
    stampaParentetica(f); printf("\n");
    
    int elem = trova_massimo(f);
    printf("%d\n", elem);
    
    printf("funzione 11.2\n");
    int elem1 = somma_foglie(f);
    printf("%d\n", elem1);
    
    printf("funzione 11.3\n");
    int elem2 = cerca_livello(f, 5);
    printf("%d\n", elem2);
    
    printf("funzione 11.4\n");
    int elem3 = conta_dispari(f);
    printf("%d\n", elem3);
    
    printf("funzione 11.5\n");
    int elem4 = somma_singoli(f);
    printf("%d\n", elem4);
    
    printf("funzione 11.6\n");
    TipoAlbero A = creaAlbBin(7, albBinVuoto(), albBinVuoto());
    TipoAlbero B = creaAlbBin(12, albBinVuoto(), albBinVuoto());
    TipoAlbero C = creaAlbBin(9, A, B);
    stampaParentetica(C); printf("\n");
    TipoLista l = albero_lista(C, listaVuota());
    printlist(l);
    
    printf("funzione 11.7\n");
    TipoLista l1 = percorso_lungo(f);
    printlist(l1);
    
    printf("funzione 11.8\n");
    TipoAlbero D = somma_sottoalbero(f);
    stampaParentetica(D); printf("\n");
    
    printf("funzione 11.9\n");
    TipoAlbero g = scambia_foglie(f);
    stampaParentetica(g); printf("\n");
    
    printf("funzione 12.2\n");
    int elem5 = livelli_completi(f);
    printf("%d\n", elem5);
    
    printf("funzione 12.1\n");
    stampaParentetica(f); printf("\n");
    int elem6 = singleChildSum(f);
    printf("%d\n", elem6);
    
    printf("funzione 12.3\n");
    TipoLista l2 = listaNodiFoglia(f, listaVuota());
    printlist(l2);
    
    printf("funzione 12.5\n");
    TipoAlbero h = taglia_livello(f, 0);
    stampaParentetica(h); printf("\n");


    return 0;
}
