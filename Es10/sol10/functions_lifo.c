
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "functions_lifo.h"


void stampa_sequenza_inversa(void) {

	Pila *p = pilaVuota();
	int numero;
	do {
		scanf("%d", &numero);
		inPila(p, numero);
	} while (numero >= 0);

	puts("");
	while (!estPilaVuota(p)) {
		printf("%d\n", outPila(p));
	}
}

void rimuovi_alcuni(Pila *p, const int *rimuovere, int n) {
    // Primo elemento
    int val = primoPila(p);

    // Cerca in rimuovere
    for (int i = 0; i < n; ++i) {
        if (rimuovere[i] == val) {
            outPila(p);
        }
        else
        {
            break;
        }
        val = primoPila(p);
    }
}

bool check_palindrome(const char *s) {
	int len = strlen(s);
	if (len % 2 == 1) {
		return false;
	}
	Pila *p = pilaVuota();
	while (len > 0) {
		inPila(p, *s);
		len -= 2;
		++s;
	}
	while (!estPilaVuota(p)) {
		char c = outPila(p);
		if (c != *s) {
			return false;
		}
		++s;
	}
	return true;
}

bool check_palindrome_r_aux(const char **s, int half_len) {
	if (half_len <= 0) {
		return true;
	}
	char c1 = **s;
	++*s;
	bool ok = check_palindrome_r_aux(s, half_len - 1);
	char c2 = **s;
	++*s;
	return ok && c1 == c2;
}

bool check_palindrome_r(const char *s) {
	int len = strlen(s);
	if (len % 2 == 1) {
		return false;
	}
	return check_palindrome_r_aux(&s, len / 2);
}

int* rimuoviMinori(int* arr, int len)
{
    Pila* tempPila = pilaVuota();
    int i=0;
    int elements_count = 0;
    while(i<len)
    {
        while(!estPilaVuota(tempPila) && primoPila(tempPila) > arr[i])
        {
            outPila(tempPila);
            elements_count--;
        }
        inPila(tempPila, arr[i]);
        elements_count++;
        i++;
    }

    int* resultArray = (int*) malloc(sizeof(int) * elements_count);

    i=0;
    while(!estPilaVuota(tempPila))
    {
        resultArray[i] = outPila(tempPila);
        i++;
    }
    return resultArray;
}
