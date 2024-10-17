#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define EPS 1e-5
// Nota, la stessa epsilon potrebbe non essere adatta per tutti i confronti


int main(void) {

	float sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		sum += 0.1f;
	}
	//NOTA: non siamo sicuri che questo test vada a buon fine: 
	//molto dipende da come sono rappresentati i numeri a virgola mobile,
	//dato che, sebbene aritmeticamente la somma dovrebbe essere esattamente 1.0f,
	//questo valore potrebbe trovarsi in un "buco" tra numeri rappresentabili successivi
	bool test = (sum == 1.0f);

	printf("%f\n", sum);
	printf("%s\n", test? "true": "false");  // Stampa falso
	printf("%.15f\n", 1.0 - sum);           // Mostra l'errore di arrotondamento

	//Per risolvere questo problema testiamo invece che la distanza (differenza in valore assoluto)
	//tra il valore di sum ed il valore costante 1.0, sia minore di un valore epsilon "molto piccolo" 
	test = fabs(sum - 1.0) < EPS;           // Confronta in range 
	printf("%s\n", test? "true": "false");  // Stampa vero
}
