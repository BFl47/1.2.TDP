#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "insf_scl.h"

#define ARRAY_LEN(a) ((int)(sizeof(a) / sizeof(*(a))))


Insieme init(int *arr, int n);
Insieme init_r(int *arr, int n);
Insieme copy(Insieme s);
Insieme copy_r(Insieme s);
void print(Insieme s);
void print_r(Insieme s);
int size(Insieme s);
int size_r(Insieme s);
bool subset(Insieme a, Insieme b);
bool subset_r(Insieme a, Insieme b);
bool equal(Insieme a, Insieme b);
bool equal_r(Insieme a, Insieme b);
Insieme intersection(Insieme a, Insieme b);
Insieme intersection_r(Insieme a, Insieme b);
Insieme set_union(Insieme a, Insieme b);
Insieme set_union_r(Insieme a, Insieme b);


// Tests per la correttezza degli esercizi
int main(void) {
	int a0[] = {0, 1, 0, 1};
	int a1[] = {0, 1, 3, -3, -11};
	int a2[] = {0, 1, -3, -13};
	int a3[] = {1};

	Insieme s0 = init(a0, ARRAY_LEN(a0));
	Insieme s1 = init(a1, ARRAY_LEN(a1));
	Insieme s2 = init(a2, ARRAY_LEN(a2));
	Insieme s3 = init(a3, ARRAY_LEN(a3));

	// Test size, print
	printf("lunghezza di ");
	print(s0);
	printf(": %d\n", size(s0));

	printf("lunghezza di ");
	print(s1);
	printf(": %d\n", size(s1));

	printf("lunghezza di ");
	print_r(s2);
	printf(": %d\n", size_r(s2));

	printf("lunghezza di ");
	print_r(s3);
	printf(": %d\n\n", size_r(s3));

	// Test init, equal
	Insieme s0_r = init_r(a0, ARRAY_LEN(a0));
	Insieme s1_r = init_r(a1, ARRAY_LEN(a1));
	Insieme s2_r = init_r(a2, ARRAY_LEN(a2));
	Insieme s3_r = init_r(a3, ARRAY_LEN(a3));

	print(s0_r);
	printf(" equals ");
	print(s0);
	printf("? %s\n", equal(s0, s0_r)? "Y": "N");

	print(s1_r);
	printf(" equals ");
	print(s1);
	printf("? %s\n", equal(s1, s1_r)? "Y": "N");

	print(s2_r);
	printf(" equals ");
	print(s2);
	printf("? %s\n", equal_r(s2, s2_r)? "Y": "N");

	print(s3_r);
	printf(" equals ");
	print(s3);
	printf("? %s\n", equal_r(s3, s3_r)? "Y": "N");

	print(s0);
	printf(" equals ");
	print(s1);
	printf("? %s\n\n", equal_r(s0, s1)? "Y": "N");

	// Test copy
	printf("Copy of ");
	print(s0);
	printf(" is equal? %s\n", equal(s0, copy(s0))? "Y": "N");

	printf("Copy of ");
	print(s1);
	printf(" is equal? %s\n", equal(s1, copy(s1))? "Y": "N");

	printf("Copy of ");
	print(s2);
	printf(" is equal? %s\n", equal(s2, copy_r(s2))? "Y": "N");

	printf("Copy of ");
	print(s3);
	printf(" is equal? %s\n\n", equal(s3, copy_r(s3))? "Y": "N");

	// Test union
	printf("Union of ");
	print(s0);
	printf(" and ");
	print(s2);
	printf(": ");
	print(set_union(s0, s2));
	putchar('\n');

	printf("Union of ");
	print(s2);
	printf(" and ");
	print(s1);
	printf(": ");
	print(set_union(s2, s1));
	putchar('\n');

	printf("Union of ");
	print(s0);
	printf(" and ");
	print(s3);
	printf(": ");
	print(set_union_r(s0, s3));
	putchar('\n');

	printf("Union of ");
	print(s1);
	printf(" and ");
	print(s2);
	printf(": ");
	print(set_union_r(s1, s2));
	putchar('\n');
	putchar('\n');

	// Test inters
	printf("Intersection of ");
	print(s0);
	printf(" and ");
	print(s2);
	printf(": ");
	print(intersection(s0, s2));
	putchar('\n');

	printf("Intersection of ");
	print(s2);
	printf(" and ");
	print(s1);
	printf(": ");
	print(intersection(s2, s1));
	putchar('\n');

	printf("Intersection of ");
	print(s0);
	printf(" and ");
	print(s3);
	printf(": ");
	print(intersection_r(s0, s3));
	putchar('\n');

	printf("Intersection of ");
	print(s1);
	printf(" and ");
	print(s2);
	printf(": ");
	print(intersection_r(s1, s2));
	putchar('\n');

	printf("Intersection of ");
	print(s0);
	printf(" and ");
	print(insiemeVuoto());
	printf(": ");
	print(intersection_r(s0, insiemeVuoto()));
	putchar('\n');
	putchar('\n');

	// Test subset
	print(s0);
	printf(" subset of ");
	print(s1);
	printf("? %s\n", subset(s0, s1)? "Y": "N");

	print(s1);
	printf(" subset of ");
	print(s2);
	printf("? %s\n", subset(s1, s2)? "Y": "N");

	print(insiemeVuoto());
	printf(" subset of ");
	print(s1);
	printf("? %s\n", subset(insiemeVuoto(), s1)? "Y": "N");

	print(s0);
	printf(" subset of ");
	print(s1);
	printf("? %s\n", subset_r(s0, s1)? "Y": "N");

	print(s1);
	printf(" subset of ");
	print(s2);
	printf("? %s\n", subset_r(s1, s2)? "Y": "N");
}


Insieme init(int *arr, int n) {
	Insieme insieme = insiemeVuoto();
	for (int i = 0; i < n; ++i) {
		insieme = inserisci(insieme, arr[i]);
	}
	return insieme;
}


Insieme init_r(int *arr, int n) {
	if (n == 0) {
		return insiemeVuoto();
	}
	Insieme insieme = init_r(arr + 1, n - 1);
	return inserisci(insieme, *arr);
}


Insieme copy(Insieme ins) {
	Insieme inscopy = insiemeVuoto();
	IteratoreInsieme it = creaIteratoreInsieme(ins);
	while (hasNext(it)) {
		inscopy = inserisci(inscopy, next(it));
	}
	return inscopy;
}


Insieme copy_r_aux(IteratoreInsieme it) {
	if (!hasNext(it)) {
		return insiemeVuoto();
	}
	T elem = next(it);
	Insieme ins = copy_r_aux(it);
	return inserisci(ins, elem);
}


Insieme copy_r(Insieme ins) {
	return copy_r_aux(creaIteratoreInsieme(ins));
}


void print(Insieme s) {
	IteratoreInsieme it = creaIteratoreInsieme(s);
	putchar('{');
	while (hasNext(it)) {
		printf("%d", next(it));
		if (hasNext(it)) {
			printf(", ");
		}
	}
	printf("}");
}


void print_r_aux(IteratoreInsieme it) {
	if (!hasNext(it)) return;
	printf("%d", next(it));
	if (hasNext(it)) {
		printf(", ");
	}
	print_r_aux(it);
}


void print_r(Insieme s) {
	putchar('{');
	print_r_aux(creaIteratoreInsieme(s));
	putchar('}');
}


int size(Insieme s) {
	int i = 0;
	IteratoreInsieme it = creaIteratoreInsieme(s);
	for (; hasNext(it); ++i, next(it));
	return i;
}


int size_r_aux(IteratoreInsieme it) {
	if (!hasNext(it)) return 0;
	next(it);
	return 1 + size_r_aux(it);
}


int size_r(Insieme s) {
	return size_r_aux(creaIteratoreInsieme(s));
}


bool subset(Insieme a, Insieme b) {
	IteratoreInsieme ita = creaIteratoreInsieme(a);
	while (hasNext(ita)) {
		if (!membro(b, next(ita))) return false;
	}
	return true;
}


bool subset_r_aux(IteratoreInsieme ita, Insieme b) {
	if (!hasNext(ita)) return true;
	if (!membro(b, next(ita))) return false;
	return subset_r_aux(ita, b);
}


bool subset_r(Insieme a, Insieme b) {
	return subset_r_aux(creaIteratoreInsieme(a), b);
}


bool equal(Insieme a, Insieme b) {
	return equal_r(a, b);
}


bool equal_r(Insieme a, Insieme b) {
	return subset_r(a, b) && subset_r(b, a);
}


Insieme intersection(Insieme a, Insieme b) {
	IteratoreInsieme ita = creaIteratoreInsieme(a);
	Insieme out = insiemeVuoto();
	while (hasNext(ita)) {
		T elem = next(ita);
		if (membro(b, elem)) {
			out = inserisci(out, elem);
		}
	}
	return out;
}


// Mostro questa variante solo per confronto con le altre funzioni _r che usano
// la funzione ausiliaria. E' forse meno efficiente?
Insieme intersection_r(Insieme a, Insieme b) {
	if (estVuoto(a)) {
		return insiemeVuoto();
	}
	T elem = next(creaIteratoreInsieme(a));
	Insieme out = intersection_r(elimina(a, elem), b);
	if (membro(b, elem)) {
		return inserisci(out, elem);
	}
	return out;
} 


Insieme set_union(Insieme a, Insieme b) {
	Insieme out = insiemeVuoto();
	for (IteratoreInsieme it = creaIteratoreInsieme(a); hasNext(it);) {
		out = inserisci(out, next(it));
	}
	for (IteratoreInsieme it = creaIteratoreInsieme(b); hasNext(it);) {
		out = inserisci(out, next(it));
	}
	return out;
}


Insieme add_all(IteratoreInsieme it, Insieme a) {
	if (!hasNext(it)) return a;
	T elem = next(it);
	return add_all(it, inserisci(a, elem));
}


Insieme set_union_r(Insieme a, Insieme b) {
	Insieme out = insiemeVuoto();
	out = add_all(creaIteratoreInsieme(a), out);
	out = add_all(creaIteratoreInsieme(b), out);
	return out;
}
