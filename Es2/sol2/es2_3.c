#include <stdio.h>

int main(){

	//Tabella caratteri ASCII https://en.wikipedia.org/wiki/ASCII#Control_code_chart	
	int c = 0;
	while(c < 128){
		printf("carattere: %c\tnumero: %d\n", c, c);
		c++;
	}
}
