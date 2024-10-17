#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int dim;
  printf("Inserire la dimensione del quadrato di asterischi: ");
  scanf("%d", &dim);

  for(int r = 0; r < dim; ++r) {
    for(int c = 0; c < dim; ++c) {
      printf("*");
    }
    printf("\n");
  }
  
  return 0;
}
