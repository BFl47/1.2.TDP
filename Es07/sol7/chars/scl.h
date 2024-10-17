
#pragma once

typedef char TipoInfoSCL;

struct ElemSCL {
	TipoInfoSCL info ;
	struct ElemSCL * next ;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;


// esercizi
TipoSCL sclstring_create(const char *s); 
void sclstring_print(const TipoSCL scl); 
bool sclstring_equals(const TipoSCL scl, const char *s);
void sclstring_remove(TipoSCL *scl_p, char val);
