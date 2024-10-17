#include <stdio.h>

//N.B.: in questa soluzione dichiariamo alcune funzioni per rendere il codice più leggibile

//Restituisce 1 se nel numero compaiono le cifre permesse (1,2,4,5,7,8) UNA e UNA SOLA volta, altrimenti restituisce 0
int verifica_cifre(int numero)
{
	int cifra_1 = 0;
	int cifra_2 = 0;
	int cifra_4 = 0;
	int cifra_5 = 0;
	int cifra_7 = 0;
	int cifra_8 = 0;

	// Conta le occorrenze di ciascuna cifra PERMESSA
	while(numero > 0) {
		switch(numero % 10){
		  //Se compare una cifra PROIBITA (0, 3, 6, 9), restituisci 0
		  case 0: case 6: case 3: case 9:
			return 0; break;
		  case 1: cifra_1 ++; break;
		  case 2: cifra_2 ++; break;
		  case 4: cifra_4 ++; break;
		  case 5: cifra_5 ++; break;
		  case 7: cifra_7 ++; break;
		  case 8: cifra_8 ++; break;
		}
		//NOTA: la variabile 'numero' contiene una copia del valore passato a questa funzione, 
		//dunque non andiamo a modificare il valore originario ma solo quello locale al campo ("scope") 
		//di questa funzione
		numero = numero/10;
	}

	// Se siamo arrivati fin qui il numero non conteneva cifre proibite (ma non abbiamo ancora garanzie che
	// tutte le cifre richieste fossero presenti e che comparissero una sola volta, cosa che verificheremo ora)

	// Verifica che tutte le cifre siano presenti UNA e UNA SOLA volta, altrimenti restituisci 0
	if (!((cifra_1 == 1) && (cifra_2 == 1) && (cifra_4 == 1) &&
	    (cifra_5 == 1) && (cifra_7 == 1) && (cifra_8 == 1))) {
		return 0;
	}

	return 1;
}

//Restituisce 1 se tutti i multipli con fattori da 1 (il multiplo è il numero stesso) a 6 hanno le cifre corrette, altrimenti restituisce 0
int verifica_multipli(int numero) {

	//Per ogni multiplo con fattore in [1,6], verifica che le cifre siano corrette
	//N.B.: verificare il multiplo con fattore 1 significa verificare il numero stesso
	for(int k = 1; k <= 6; k++) {

  		int multiplo = numero*k;

		//Verifica che le cifre del numero siano corrette (se non lo sono, restituisci 0)
		if (!verifica_cifre(multiplo)) 
			return 0;	
	}
	//Se sono arrivato fin qui, significa che tutti i multipli vanno bene
	return 1;
}

int main(){

  int const MIN_NUMBER = 124578;
  int const MAX_NUMBER = 875421;


  int numero_candidato = MIN_NUMBER;

  //Per ogni numero intero nell'intervallo [124578, 875421]
  while(numero_candidato < 875421){

	//Verifica che il numero stesso e i suoi multipli siano OK
	if(verifica_multipli(numero_candidato)) 
	{
		//Se entriamo in questo blocco signica che verifica_multipli ha restituito un valore non nullo (in particolare, ha restituito 1, come un valore booleano True)
	    //dunque abbiamo trovato un numero straordinario
		break;
	}
	numero_candidato = numero_candidato + 1; //o equivalentemente numero_candidato++
  }
  printf("Numero straordinario = %d\tper 2 = %d\tper 3 = %d\tper 4 = %d\tper 5 = %d\tper 6 = %d\n", numero_candidato, numero_candidato*2, numero_candidato*3, numero_candidato*4, numero_candidato*5, numero_candidato*6);
}
