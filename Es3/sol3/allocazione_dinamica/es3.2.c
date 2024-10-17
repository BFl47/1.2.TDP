#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv) {
  int *data = (int *)malloc(2 * sizeof(int));

	*data = 0;       // numero
	*(data + 1) = 0; // minimo

	bool error = false;

  while (1) {
    printf("Inserire un numero positivo (0 per terminare): ");
    scanf("%d", data);

		if (*data == 0) break;

		if (*data < 0) {
			printf("Error: negative number\n");
			error = true;
			break;
		}

    if(*data < *(data + 1) || *(data + 1) == 0) {
      *(data + 1) = *data;
    }
  }

	if (!error) {
		printf("Il numero minimo inserito e': %d\n", *(data + 1));
	}

  free(data);
	data = NULL;
	return error;
} 
