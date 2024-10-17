#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int m;
  printf("Inserire la dimensione del blocco M: ");
  scanf("%d", &m);

  if(m < 1) {
    printf("Il blocco deve avere dimensione strettamente positiva!\n");
    return -1;
  }

  int n;
  printf("Inserire la dimensione della scacchiera N: ");
  scanf("%d", &n);

  if(n < 1) {
    printf("La scacchiera deve avere dimensione strettamente positiva!\n");
    return -1;
  }
    

  for(int r = 0; r < m * n; ++r) {
    for(int c = 0; c < m * n; ++c) {
      if((r / m) % 2 == 0) {
        if((c / m) % 2 == 0) {
          printf("*");
        }
        else {
          printf("_");
        }
      }
      else {
        if((c / m) % 2 != 0) {
          printf("*");
        }
        else {
          printf("_");
        }
      }
    }
    printf("\n");
  }

  return 0;
}
