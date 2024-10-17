#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int num_inserimenti = 0;
  float num, accumulatore = 0.0;

  printf("Inserire un numero (0.0 per terminare): ");
  scanf("%f", &num);

  while(num != 0.0) {
    num_inserimenti++;
    accumulatore += num;    
    printf("Inserire un numero (0.0 per terminare): ");
    scanf("%f", &num);
  }

  if(num_inserimenti != 0) {
    printf("La media aritmetica dei numeri inseriti e': %f\n", accumulatore / (float)num_inserimenti);
  }

  return 0;
}
