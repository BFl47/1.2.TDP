#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  float x;
  printf("Inserire un numero: ");
  scanf("%f", &x);

  if(x < 0.0) {
    printf("Il numero non deve essere negativo!\n");
    return -1;
  }

  //N.B.: Il ciclo è definito perché il fattore n determina la precisione del numero
  //(infatti, più andiamo avanti nel calcolo e più la nostra approssimazione della
  //radice quadrata è precisa)
  int n = 20;
  float radice = x;
  for(int i = 0; i < n; ++i) {
    radice = (radice + x / radice) / 2.0f;
  }

  printf("La radice di %f e': %f\n", x, radice);

  return 0;
}
