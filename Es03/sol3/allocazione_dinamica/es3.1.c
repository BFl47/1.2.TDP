#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char **argv) {
  int *num = (int *)malloc(sizeof(int)); 
  int *minimo = (int *)malloc(sizeof(int));

	*minimo = 0;
	*num = 0;

  while (1) {
    printf("Inserire un numero positivo (0 per terminare): ");
    scanf("%d", num);

		if (*num == 0) break;

		if (*num < 0) {
			printf("Error: negative number\n");
			return 1;
		}

    if (*num < *minimo || *minimo == 0) {
      *minimo = *num;
    }
  }

  printf("Il numero minimo inserito e': %d\n", *minimo);
  
  free(minimo);
	minimo = NULL;
  free(num);
	num = NULL;
} 
