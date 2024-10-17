#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int a = 0, b = 0;  
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("&a = %p\n", &a);
  printf("&b = %p\n", &b);

  long dist = &a - &b; //Differenza tra gli indirizzi in memoria
  printf("dist = %ld\n", dist);
  
  *(&b + dist) = 1; //NOTA: aritmetica dei puntatori
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  
  return 0;
}
