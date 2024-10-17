/*******************************************
* Struttura collegata lineare.             *
*                                          *
* Non utilizzare direttamente.             *
* Preferire le funzioni dei tipi astratti, *
*******************************************/
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

struct NodoSCL {
	T info;
	struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
