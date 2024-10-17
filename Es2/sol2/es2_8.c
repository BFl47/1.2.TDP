#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int i = 10;   //Dimensione di un intero: 4 byte
  int j = -1; 
  char *p, *q;  //Puntatori a char (aree di memoria di 1 byte)
  
  p = (char*)&i;
  q = (char*)&j;
  //Non possiamo assegnare direttamente gli interi ma possiamo ricopiare ciascun byte
  //dell'area di memoria associata al primo nei byte di memoria associati al secondo
  for(int k = 0; k < sizeof(i); ++k) { //NOTA: sizeof(i) == 4 byte
    *(q + k) = *(p + k);    //Aritmetica dei puntatori: 
                            //  il contenuto della memoria all'indirizzo p + k * sizeof(p)
                            //  è assegnato all'area di memoria all'indirizzo q + k * sizeof(q)
  }
    
  printf("%d == %d\n", i, j); 
  
  return 0;
}
