#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "scl.h"


int main(void) {

	// Creo iniziale
	TipoSCL list = listPushFront(NULL, 2);
	list = listPushFront(list, -2);
	list = listPushFront(list, 0);
	list = listPushFront(list, -1);
	TipoSCL input = copyList(list);

	// Len
	printf("len of ");
	printList(input);
	printf(" is %d\n\n", scl_len(input));

	// Sum
	printf("sum of ");
	printList(input);
	printf(" is %f\n\n", scl_sum(input));

	// Media
	printf("average of ");
	printList(input);
	printf(" is %f\n\n", scl_media(input));

	// Dot
	printf("dot of ");
	printList(input);
	printf(" by itself is %f\n\n", scl_dot(input, list));

	// Duplicate
	printf("duplicate of ");
	printList(input);
	printf(" in position 2 is\n");
	scl_duplicate_pos(input, 2);
	printList(input);
	printf("\n");
	printf(" in position 0 is\n");
	scl_duplicate_pos(input, 0);
	printList(input);
	printf("\n\n");

	// Positives
	printf("positives of ");
	printList(input);
	printf(" is \n");
	TipoSCL positives = scl_positives(input);
	printList(positives);
	putchar('\n');

}
