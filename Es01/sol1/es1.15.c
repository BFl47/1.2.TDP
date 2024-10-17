#include <stdio.h>

int main(){

  int c1 = 0, c2 = 0, c4 = 0, c5= 0, c7 = 0, c8 = 0;
  int k;
  int i = 124578;
  int stra = 0;
  int n;

  // For each number
  while(stra == 0 && i < 875421){

    i++;
    int cifre_ok  = 1;

    // Testing each product
    for(k = 1; (k < 7) && cifre_ok; k++) {

      n = i*k;
      c1 = 0;
      c2 = 0;
      c4 = 0;
      c5 = 0;
      c7 = 0;
      c8 = 0;

      // Only the good numbers
      while(n > 0) {
        switch(n % 10){
          case 0: case 6: case 3: case 9:
            cifre_ok = 0; break;
          case 1: c1 ++; break;
          case 2: c2 ++; break;
          case 4: c4 ++; break;
          case 5: c5 ++; break;
          case 7: c7 ++; break;
          case 8: c8 ++; break;
        }
        n = n/10;
      }
      // All the good numbers
      if (!((c1 == 1) && (c2 == 1) && (c4 == 1) &&
            (c5 == 1) && (c7 == 1) && (c8 == 1))) {
        cifre_ok = 0;
      }
    }
    if(k == 7) {
       stra = 1;    
    }
  }
  printf("Numero = %d\tper 2 = %d\tper 3 = %d\tper 4 = %d\tper 5 = %d\tper 6 = %d\n", i, i*2, i*3, i*4, i*5, i*6);
}
