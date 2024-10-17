
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>


void sort_strings(const char **list) {

	// Conto le stringhe
	int n_strings = 0;
	while (list[n_strings] != NULL) ++n_strings;

	// Copio
	const char **copy = (const char **)malloc(sizeof(void *) * (n_strings + 1));
	for (int i = 0; i <= n_strings; ++i) {
		copy[i] = list[i];
	}

	// Ordino: qualsiasi algoritmo va bene. Naive qui
	for (int out_i = 0; out_i < n_strings; ++out_i) {

		// Trovo il più piccolo
		int min_len = INT_MAX;
		int min_pos = -1;
		for (int i = 0; i < n_strings; ++i) {
			if (copy[i] == NULL) continue;

			int len = strlen(copy[i]);
			if (len <= min_len) {
				min_len = len;
				min_pos = i;
			}
		}

		// Copio e lo segno come copiato (NULL)
		list[out_i] = copy[min_pos];
		copy[min_pos] = NULL;
	}
}


int main(void) {

	const char *list[] = {
		"questa",
		"e'",
		"una",
		"prova_lunga",
		"",
		NULL
	};

	sort_strings(list);

	const char **str = list;
	while (*str != NULL) {
		puts(*str);
		str++;
	}
}
