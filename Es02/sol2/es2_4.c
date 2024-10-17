#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(){
	//NOTA: 'sizeof' restituisce la dimensione in byte del tipo passato come argomento.
	//Moltiplicando questi numeri per 8 otteniamo il numero di bit di rappresentazione. 
	//Dobbiamo infine tenere in considerazione il bit di segno (sottraendo 1 al numero di bit di rappresentazione)
	int res_int_arit = pow(2, (sizeof(int) * 8) - 1) - 1;
	printf("Punto B) Il mio risultato int, calcolato aritmeticamente, è %d\n", res_int_arit);
	printf("Punto A) La soluzione, usando la libreria <limits.h>, è %d\n", INT_MAX);

	long res_long_arit = powl(2, (sizeof(long) * 8) - 1) - 1 ;
	printf("Punto B) Il mio risultato long, calcolato aritmeticamente, è %ld\n", res_long_arit);
	printf("Punto A) La soluzione, usando la libreria <limits.h>, è %ld\n", LONG_MAX);
}
