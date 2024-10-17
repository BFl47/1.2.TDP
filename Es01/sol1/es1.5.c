#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int n;
  printf("Inserire il limite n della serie di Fibonacci: ");
  scanf("%d", &n);

  if(n < 1) {
    printf("Il limite della serie deve essere un-intero strettamente positivo!\n");
    return -1;
  }

  if(n == 1) {
    printf("1\n");
    return 0;
  }

  long int f_i_1 = 1, f_i_2 = 1;
  printf("1, 1");
  for(int i = 3; i <= n; ++i) {
    long int f_i = f_i_2 + f_i_1;
    printf(", %ld", f_i);
    f_i_2 = f_i_1;
    f_i_1 = f_i;
  }
  printf("\n");

  return 0;
}
