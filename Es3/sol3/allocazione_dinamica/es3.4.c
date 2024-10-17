#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  void *data = (void *)malloc(sizeof(float) + sizeof(char)); 

	float *temperatura = (float *)data;
	char *scala = (char *)(temperatura + 1);
	
  printf("Inserire la temperatura: ");
  scanf("%f", temperatura);

  printf("Inserire la scala (K, C, F): ");
  scanf(" %c", scala);

  switch(*scala) {
  case 'K':
    printf("C: %f\n", *temperatura - 273.15f);
    printf("F: %f\n", (*temperatura - 273.15f) * 9.0f / 5.0f + 32.0f);
    break;
  case 'C':
    printf("K: %f\n", *temperatura + 273.15f);
    printf("F: %f\n", *temperatura * 9.0f / 5.0f + 32.0f);
    break;
  case 'F':
    printf("K: %f\n", ((*temperatura - 32.0f) * 5.0f / 9.0f) + 273.15f);
    printf("C: %f\n", (*temperatura - 32.0f) * 5.0f / 9.0f);
    break;
  default:
    break;
  }

  free(data);
	data = NULL;

  return 0;
}
