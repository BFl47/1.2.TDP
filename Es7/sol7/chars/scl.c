#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "scl.h"


TipoSCL sclstring_create(const char *s) {
	if (s == NULL || *s == '\0') {
		return NULL;
	}
	TipoNodoSCL *nodo = (TipoNodoSCL *)malloc(sizeof(TipoNodoSCL));
	nodo->info = *s;
	nodo->next = sclstring_create(s + 1);
	return nodo;
}


void sclstring_print(const TipoSCL scl) {
	if (scl == NULL) return;
	putchar(scl->info);
	sclstring_print(scl->next);
}


bool sclstring_equals(const TipoSCL scl, const char *s) {
	if (scl == NULL && (s == NULL || *s == '\0')) return true;
	if (scl == NULL || (s == NULL || *s == '\0')) return false;
	if (scl->info != *s) return false;
	return sclstring_equals(scl->next, s + 1);
}


void sclstring_remove(TipoSCL *scl_p, char val) {
	TipoSCL scl = *scl_p;
	if (scl == NULL) return;
	if (scl->info == val) {
		*scl_p = scl->next;  // Skip this
		free(scl);  // Delete it
		scl = NULL;
		sclstring_remove(scl_p, val);
	} else {
		sclstring_remove(&(scl->next), val);
	}
}
