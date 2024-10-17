
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define INT_ARRAY_LEN 20
#define DOUBLE_ARRAY_LEN 4


// Dichiarazioni
void random_array(int v[], int dim, int max_value);
double vec_dot(const double vec1[], const double vec2[], int dim);
double * vec_clone(const double v[], int dim); 
void vec_scale(double v[], int dim, double d); 
int * numeri_unici(const int array[], int dim, int *output_dim);

void print_array(int array[], int len);


int main(void) {

	// Test random
	srand(1234);  // Optional
	int v1[20];
	random_array(v1, INT_ARRAY_LEN, 6);
	print_array(v1, INT_ARRAY_LEN);
	puts("");

	// Test prodotto scalare
	double d1[] = {1.1, 0.0, 3.0, -1.2};
	double d2[] = {0.0, 2.0, -0.5, +2.0};
	double res = vec_dot(d1, d2, DOUBLE_ARRAY_LEN);
	printf("prodotto scalare %lf\n\n", res);

	// Test clone tramite prodotto scalare uguale
	double *d2_copia = vec_clone(d2, DOUBLE_ARRAY_LEN);
	res = vec_dot(d1, d2_copia, DOUBLE_ARRAY_LEN);
	printf("prodotto scalare %lf\n\n", res);

	// Test scala tramite prodotto scalare
	vec_scale(d2_copia, DOUBLE_ARRAY_LEN, 0.5);
	res = vec_dot(d1, d2_copia, DOUBLE_ARRAY_LEN);
	printf("prodotto scalare %lf\n\n", res);

	// Test numeri unici
	int unici_len;
	int *unici = numeri_unici(v1, INT_ARRAY_LEN, &unici_len);
	print_array(unici, unici_len);

	// Free
	free(d2_copia);
	d2_copia = NULL;
	free(unici);
	unici = NULL;
}


/*****************************************************************************
* Esercizio 4.1                                                              *
*                                                                            *
* Scrivere una funzione                                                      *
*                                                                            *
* void random_array(int v[], int dim, int max_value)                         *
*                                                                            *
* che dato in input un array v di dimensione dim, e un valore intero massimo *
* max_value, popoli l’array con valori casuali compresi tra zero e max_value *
* (excluso).                                                                 *
* Nota: usare la funzione rand() che si trova in stdlib.h                    *
*****************************************************************************/
void random_array(int v[], int dim, int max_value) {

	for (int i = 0; i < dim; ++i) {
		v[i] = rand() % max_value;
	}
}

 
/*************************************************************************
* Esercizio 4.2                                                          *
*                                                                        *
* Scrivere la funzione                                                   *
*                                                                        *
* double vec_dot(const double vec1[], const double vec2[], int dim);     *
*                                                                        *
* che, dati in ingresso due vettori della stessa dimensione dim, ritorni *
* il loro prodotto scalare.                                              *
*************************************************************************/
double vec_dot(const double vec1[], const double vec2[], int dim) {

	double risultato = 0;
	for (int i = 0; i < dim; ++i) {
		risultato += vec1[i] * vec2[i];
	}

	return risultato;
}
 

/******************************************************************************
* Esercizio 4.3                                                               *
*                                                                             *
* Scrivere la funzione                                                        *
*                                                                             *
* double* vec_clone(const double v[], int dim);                               *
*                                                                             *
* che, dato in ingresso un vettore v di dimensioni dim  allochi e restituisca *
* una copia del vettore v.                                                    *
******************************************************************************/
double * vec_clone(const double v[], int dim) {

	double *copia = (double *)malloc(dim * sizeof(double));
	for (int i = 0; i < dim; ++i) {
		copia[i] = v[i];
	}

	return copia;
}
 

/*******************************************************************************
* Esercizio 4.4                                                                *
*                                                                              *
* Scrivere la funzione                                                         *
*                                                                              *
* void vec_scale(double v[], int dim, double scale)                            *
*                                                                              *
* che dato in ingresso un vettore v di dimensione dim , modifichi v scalando   *
* le sue componenti di un fattore scale. Per “scalare” si intende moltiplicare *
* tutte le sue componenti del valore scale.                                    *
*******************************************************************************/
void vec_scale(double v[], int dim, double d) {
	for (int i = 0; i < dim; ++i) {
		v[i] *= d;
	}
}

 
/******************************************************************************
* Esercizio 4.5                                                               *
*                                                                             *
* Scrivere una funzione                                                       *
*                                                                             *
* int * numeri_unici(const int array[], int dim, int *output_dim);            *
*                                                                             *
* che, dato un input un array di interi lungo dim, ritorni un nuovo array che *
* non contiene ripetizioni (solo la prima occorrenza di ogni numero va        *
* mantenuta). La lunghezza dell’array ritornato deve essere salvata           *
* nell’intero puntato da output_dim.                                          *
*                                                                             *
* Esempio                                                                     *
* input: [2, -11, 0, -11, 2, 2, 1]                                            *
* output: [2, -11, 0, 1]                                                      *
******************************************************************************/
int * numeri_unici(const int array[], int dim, int *output_dim) {

	int *unici = (int *)malloc(dim * sizeof(int));

	int array_i = 0, unici_i = 0;  // Indici per entrambi gli array

	// Scorri l'input
	while (array_i < dim) {
		int corrente = array[array_i];

		// Trova corrente nell'output
		bool trovato = false;
		for (int j = 0; j < unici_i; ++j) {
			if (unici[j] == corrente) {
				trovato = true;
				break;
			}
		}

		// Copia se è nuovo
		if (!trovato) {
			unici[unici_i++] = corrente;
		}
		++array_i;
	}

	// Ritorno la dimensione dell'output
	*output_dim = unici_i;

	// Opzionale! rilascio la memoria in eccesso. Solo come dimostrazione.
	unici = (int *)realloc(unici, unici_i);

	return unici;
}


// Utility
void print_array(int array[], int len) {

	putchar('[');
	for (int i = 0; i < len; ++i) {
		const char *format = (i < len - 1)? "%d, ": "%d";
		printf(format, array[i]);
	}
	puts("]");
}
