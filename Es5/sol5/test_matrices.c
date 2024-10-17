#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "matrices.h"


int main(int argc, char **argv) {
  /********************************************************
  *             TEST Mat_alloc/Mat_read                  *
  ********************************************************/
  printf("Leggo m1 dal file mat_1.txt...");
  Mat *m1 = Mat_read("mat_1.txt");
  printf(" fatto.\n\n");

  /********************************************************
  *                    TEST Mat_print                    *
  ********************************************************/
  printf("m1:\n");
  Mat_print(m1);
  printf("\n");

  /********************************************************
  *                    TEST Mat_write                    *
  ********************************************************/
  printf("Scrivo una copia di m1 in copia_mat_1.txt...");
  Mat_write("copia_mat_1.txt", m1);
  printf(" fatto.\n\n");

  /********************************************************
  *                TEST Mat_is_symmetric                 *
  ********************************************************/
  printf("Leggo m2 dal file mat_1.txt...");
  Mat *m2 = Mat_read("mat_1.txt");
  printf(" fatto.\n");
  printf("m2:\n");
  Mat_print(m2);  
  printf("La matrice m2 e' simmetrica?\n");
  int is_symmmetric = Mat_is_symmetric(m2);
  if(is_symmmetric) {
    printf("Si e' simmetrica.\n");
  }
  else {
    printf("No non e' simmetrica.\n");
  }
  printf("\n");

  /********************************************************
  *               TEST Mat_normalize_rows                *
  ********************************************************/
  printf("Leggo m3 dal file mat_1.txt...");
  Mat *m3 = Mat_read("mat_1.txt");
  printf(" fatto.\n");
  printf("m3:\n");
  Mat_print(m3);  
  printf("Normalizzo le righe della matrice m3...");
  Mat_normalize_rows(m3);
  printf(" fatto.\n");
  printf("La matrice m3 con righe normalizzate e':\n");
  Mat_print(m3);
  printf("\n");

  /********************************************************
  *                    TEST Mat_clone                    *
  ********************************************************/
  printf("Clono m2...");
  Mat *copy_m2 = Mat_clone(m2);
  printf(" fatto.\n");
  printf("Copia m2:\n");
  Mat_print(copy_m2);  
  printf("\n");

  /********************************************************
  *                    TEST Mat_sum                       *
  ********************************************************/
  printf("Sommo m2 e m3...\n");
  Mat *sum_m2_m3 = Mat_sum(m2, m3);
  if( sum_m2_m3 != NULL ){
    printf(" fatto.\n");
    Mat_print(sum_m2_m3); 
  } 
  printf("\n");

  /********************************************************
  *                    TEST Mat_product                   *
  ********************************************************/
  printf("leggo m4 e ne eseguo il prodotto con m1...\n");
  Mat *m4 = Mat_read("mat_1.txt");
  Mat *product_m1_m4 = Mat_product(m1, m4);
  if( product_m1_m4 != NULL ){
    printf(" fatto.\n");
    Mat_print(product_m1_m4); 
  }  
  printf("\n");

  /********************************************************
   *                    TEST Mat_free                     *
   ********************************************************/
  Mat_free(copy_m2);
  Mat_free(m4);
  Mat_free(m3);
  Mat_free(m2);
  Mat_free(m1);

  return 0;
}
