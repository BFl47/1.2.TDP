#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  float valore;
  scanf("%f", &valore);

  while(valore != 0.0) {
    for(int i = 0; i < valore; ++i) {
      printf("*");
    }
    printf("\n");
    scanf("%f", &valore);
  }

  return 0;
}
