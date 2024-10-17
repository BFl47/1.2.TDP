#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  float num, minimo;
  printf("Inserire un numero (0.0 per terminare): ");
  scanf("%f", &num);
  minimo = num;

  while(num != 0.0) {
    printf("Inserire un numero (0.0 per terminare): ");
    scanf("%f", &num);
    if(num < minimo && num != 0.0) {
      minimo = num;
    }
  }

  printf("Il numero minimo inserito e': %f\n", minimo);

  return 0;
}
