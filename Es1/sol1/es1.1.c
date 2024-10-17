#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  float a;
  printf("Inserire il coefficiente a: ");
  scanf("%f", &a);

  if(a == 0.0) {
    printf("Il coefficiente a deve essere diverso da zero!\n");
    return -1;
  }

  float b;
  printf("Inserire il coefficiente b: ");
  scanf("%f", &b);

  printf("x = - b / a = %f\n", - b / a);

  return 0;
}
