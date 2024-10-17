#include "albero_binario.h"
#include "lista.h"

TipoInfoAlbero trova_massimo(TipoAlbero a);                 //11.1
int max(int a, int b);
bool estFoglia(TipoAlbero a);
TipoInfoAlbero somma_foglie(TipoAlbero a);                  //11.2
int cerca_livello(TipoAlbero a, TipoInfoAlbero v);          //11.3
int cerca_livello_aux(TipoAlbero a, TipoInfoAlbero v, int lv);
int conta_dispari(TipoAlbero a);                            //11.4
bool un_successore(TipoAlbero a);
int somma(TipoAlbero a);
int somma_singoli(TipoAlbero a);                            //11.5
TipoLista albero_lista(TipoAlbero a, TipoLista ris);        //11.6
TipoLista percorso_lungo(TipoAlbero a);                     //11.7
TipoAlbero somma_sottoalbero(TipoAlbero a);                 //11.8
bool padredidue(TipoAlbero a);
TipoAlbero scambia_foglie(TipoAlbero a);                    //11.9

int livelli_completi(TipoAlbero a);                         //12.2
void liv_aux(TipoAlbero a, int* array);
int singleChildSum(TipoAlbero a);                           //12.1
TipoLista listaNodiFoglia(TipoAlbero a, TipoLista ris);     //12.3
TipoAlbero taglia_livello(TipoAlbero a, int livello);       //12.5
