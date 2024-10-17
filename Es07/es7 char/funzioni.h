#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char TipoInfoSCL;
struct ElemSCL {
TipoInfoSCL info;
struct ElemSCL *next;
};
typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

void addSCL(TipoSCL *scl, TipoInfoSCL e);
void scl_stamp(TipoSCL scl);

TipoSCL sclstring_create(const char *s);                    //7.8
bool sclstring_equals(TipoSCL scl, const char *s);          //7.9
void sclstring_remove(TipoSCL *scl_p, char val);            //7.10