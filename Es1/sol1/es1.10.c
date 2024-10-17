#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int n;
  printf("Inserire il numero di cifre binarie: ");
  scanf("%d", &n);

  int num = 0;
  int i;
  for(i = 0; i < n; ++i) {    
    int cifra;
    printf("Inserire la cifra binaria in posizione %d: ", i);
    scanf("%d", &cifra);

    num += cifra * pow(2, i);
  }
  printf("Il numero binario inserito corrisponde al numero decimale: %d\n", num);
}
