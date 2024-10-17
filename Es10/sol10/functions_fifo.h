#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "coda.h"

void stampa_sequenza();
int elemento_iesimo(Coda* c, int pos);
void avoid_stampa(Coda* c, int elem);
Coda* coda_circolare(Coda* c, int n);
Coda* elementi_pari(Coda* c);
Coda* rimuovi_positivi(Coda* c);