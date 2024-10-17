#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n;
	int *p;
	int i;

	printf("Inserisci il numero N di interi ");
	scanf("%d", &n);

	p = (int *)malloc(n * sizeof(int));
	for(i = 0; i < n; i++){
		printf("Posizione %d  indirizzo = %p  contenuto = %d\n", i, p+i, *(p+i));
	}

	free(p);
	p = NULL;
}
