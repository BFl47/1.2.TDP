
#include <stdbool.h>

#include "alberi_funz.h"
#include "liste_funz.h"
#include "mat.h"

int singleChildSum(TipoAlbero a);
int livelliCompleti(TipoAlbero a);
TipoLista listaNodiFoglia(TipoAlbero a);
TipoAlbero taglia_livello(TipoAlbero a, int livello);
int conditionalSum(const FloatMat *m, int flag);
int contieneElemento(TipoSCL l, TipoInfoSCL e);
TipoSCL complemento(TipoSCL scl, TipoSCL elementiDaScartare);
int next_step(CharMat *m, char direction);
TipoLista inFondo(TipoLista l);
TipoLista invertiInParte(TipoLista l, int inizio);
