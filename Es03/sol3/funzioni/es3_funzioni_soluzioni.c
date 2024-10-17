#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int * allocaInt();

void printInt(int *i1, int *i2);

int MCD(int i1, int i2);

int mcm(int i1, int i2);

void conversioneTemperatura(float t, char c);

void * conversioneTemperaturaP(float *t, char c);

void printConversione(void *conversioni);

void soluzioneEquazione(int a, int b, int c);


int main(int argc, char **argv) {
	/*****************
	* Test allocaInt *
	*****************/
  int *i1 = allocaInt();
  int *i2 = allocaInt();
  printf("i1 pointer %p\n", i1);
  printf("i2 pointer %p\n", i2);
	printf("\n");

	/****************
	* Test printInt *
	****************/
  printf("i1, i2: ");
  printInt(i1, i2);
  printf("\n");

	/*****************
	* Test MCD e mcm *
	*****************/
	*i1 = 110;
	*i2 = 20;
  printf("calcolo il MCD...\n");
  int mcd = MCD(*i1, *i2);
  printf("il MCD è %d\n\n", mcd);

  printf("calcolo il mcm...\n");
  int res = mcm(*i1, *i2);
  printf("il mcm è %d\n\n", res);

	/******************************
	* Test conversioneTemperatura *
	******************************/
	float t1 = *i1;
	float t2 = *i2;
  printf("test conversioneTemperatura...\n");
  conversioneTemperatura(t2, 'C');
	printf("\n");

	/**************************************************
	* Test conversioneTemperaturaP e printConversione *
	**************************************************/
  printf("test conversioneTemperaturaP\n");
	void *conversioni = conversioneTemperaturaP(&t2, 'C');

  printf("test printConversione\n");
  printConversione(conversioni);
  free(conversioni);
	conversioni = NULL;
  printf("\n");

	/**************************
	* Test soluzioneEquazione *
	**************************/
  printf("Calcolo la soluzione dell'equazione di secondo grado...\n");
  printf("a, b, c: %d, %d, %d\n", 1, -6, 5);
  soluzioneEquazione(1, -6, 5);
  printf("a, b, c: %d, %d, %d\n", 0, 4, 5);
  soluzioneEquazione(0, 4, 5);
 
  free(i1);
	i1 = NULL;
  free(i2);
	i2 = NULL;
}

int * allocaInt(){
  return (int *)malloc(sizeof(int));
}

void printInt(int *i1, int *i2){
  printf("%d %d", *i1, *i2);
}

int MCD(int i1, int i2){
	while (i1 != i2) {
		if (i1 > i2) {
			i1 = i1 - i2;
		}
		else { 
			i2 = i2 - i1;
		}
	}

	return i1;
}

int mcm(int i1, int i2){
  return (i1*i2)/MCD(i1,i2);
}

void conversioneTemperatura(float t, char c){
  switch(c) {
  case 'K':
    printf("C: %f\n", t - 273.15f);
    printf("F: %f\n", (t - 273.15f) * 9.0f / 5.0f + 32.0f);
    break;
  case 'C':
    printf("K: %f\n", t + 273.15f);
    printf("F: %f\n", t * 9.0f / 5.0f + 32.0f);
    break;
  case 'F':
    printf("K: %f\n", ((t - 32.0f) * 5.0f / 9.0f) + 273.15f);
    printf("C: %f\n", (t - 32.0f) * 5.0f / 9.0f);
    break;
  default:
    break;
  }
}

void * conversioneTemperaturaP(float *t, char c){

	// Data buffer
	void *conversioni = malloc(2 * sizeof(float) + 2 * sizeof(char));

	float *t1 = (float *)conversioni;
	char *c1 = (char *)conversioni + sizeof(float);
	float *t2 = (float *)((char *)conversioni + sizeof(float) + sizeof(char));
	char *c2 = (char *)conversioni + 2 * sizeof(float) + sizeof(char);

  switch(c) {
  case 'K':
		// C
		*t1 = *t - 273.15f;
		*c1 = 'C';
		// F
		*t2 = (*t - 273.15f) * 9.0f / 5.0f + 32.0f;
		*c2 = 'F';
    break;
  case 'C':
		// K
		*t1 = *t + 273.15f;
		*c1 = 'K';
		// F
		*t2 = *t * 9.0f / 5.0f + 32.0f;
		*c2 = 'F';
    break;
  case 'F':
		// K
		*t1 = *t + 273.15f;
		*c1 = 'K';
		// C
		*t2 = *t - 273.15f;
		*c2 = 'C';
    break;
  default:
    break;
  }

	return conversioni;
}

void printConversione(void *conversioni){
	float *t1 = (float *)conversioni;
	char *c1 = (char *)conversioni + sizeof(float);
	float *t2 = (float *)((char *)conversioni + sizeof(float) + sizeof(char));
	char *c2 = (char *)conversioni + 2 * sizeof(float) + sizeof(char);

	printf("%c: %f\n", *c1, *t1);
	printf("%c: %f\n", *c2, *t2);
}

void soluzioneSistemaLineare(int a, int b){
	printf("x = %f\n", -(float)b / (float)a);
}

void soluzioneEquazione(int a, int b, int c){

	// Optional, just as an example
  if (a == 0){
    soluzioneSistemaLineare(b, c);
    return;
  }

  int delta = pow(b, 2) - 4*a*c;

  if (delta < 0){
    printf("Il delta e' negativo!");
    return;
  }

  float x1 = -b + sqrt(delta);
  float x2 = -b - sqrt(delta);
  
  x1 = x1 / (2*a);
  x2 = x2 / (2*a);

  printf("x1 = %f\nx2 = %f\n", x1, x2);

}
