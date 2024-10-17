#include "pila.h"

void stampa_sequenza_inversa(void);                             //10.1
void rimuovi_alcuni(Pila *p, const int *rimuovere, int n);      //10.2
bool inArray(const int* arr, int n, int elem);
bool check_palindrome(const char* s);                           //10.3
bool check_palindrome_aux(const char* s, int len);
Pila* init(const char* s, int len);
int* rimuoviMinori(int* arr, int len);                          //10.5