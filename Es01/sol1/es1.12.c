#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) 
{
  int n1;
  printf("Inserire un primo numero positivo intero: ");
  scanf("%d", &n1);

  int n2;
  printf("Inserire un secondo numero positivo intero: ");
  scanf("%d", &n2);

  long prodotto = n1*n2;
  long mcm = (n1 > n2)? n1: n2;  // Parto dal più grande dei due
  
  for(; mcm <= prodotto; mcm++) 
  {
    if(mcm % n1 == 0 && mcm % n2 == 0)
      break;
  }
  printf("Il minimo comune multiplo e': %ld\n", mcm);

  return 0;
}
