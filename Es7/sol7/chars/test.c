#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "scl.h"


int main(void) {

	// Creo iniziale
	const char *in = "This is a simple string\n";
	TipoSCL scl = sclstring_create(in);

	// Print
	sclstring_print(scl);

	// Equals
	const char *in1 = "This Xis a simple stringX\n";
	printf("Equals should be 0: %d\n", sclstring_equals(scl, in1));

	// Remove
	TipoSCL scl1 = sclstring_create(in1);
	printf("X removed from: ");
	sclstring_print(scl1);
	sclstring_remove(&scl1, 'X');
	printf("Now equals should be 1: %d\n", sclstring_equals(scl1, in));
}
