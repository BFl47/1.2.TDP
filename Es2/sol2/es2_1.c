#include <stdio.h>

int main(){
	int i;
	char c;
	short si;
	long li;
	float f;
	double d;
	
	printf("%lu\t%lu\t%lu\t%lu\t%lu\t%lu\n", sizeof(i),sizeof(c),sizeof(si),sizeof(li),sizeof(f),sizeof(d));
}
