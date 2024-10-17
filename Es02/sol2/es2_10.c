#include <stdio.h>
#include <math.h>
//Lo scopo di questo esercizio è determinare che dimensione hanno i puntatori
int main(){
	
	int n, *p;
	p = &n;
	
	unsigned int i;
	unsigned long int li;
	unsigned long long int lli;
	
	if((long long int)p <= pow(2,(sizeof(i)*8) -1 ) ){
		printf("caso 1: il puntatore %p puo' essere rappresentato da un int\n", p);
	}else if( (long long int)p <= pow(2,(sizeof(li)*8) -1 )  ){
		printf("caso 1: il puntatore %p puo' essere rappresentato da un long int\n", p);
	}else{
		printf("caso 1: il puntatore %p puo' essere rappresentato da un long long int\n", p);
	}  
}
