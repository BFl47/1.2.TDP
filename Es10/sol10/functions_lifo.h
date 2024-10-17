#pragma once

#include "pila.h"

void stampa_sequenza_inversa();
void rimuovi_alcuni(Pila *p, const int *rimuovere, int n);

bool check_palindrome(const char* s);
bool check_palindrome_r(const char *s);

int* rimuoviMinori(int* arr, int len);