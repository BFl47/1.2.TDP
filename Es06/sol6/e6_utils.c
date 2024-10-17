#include "e6_utils.h"

// Legge righe da file.
char ** read_lines(const char filepath[], int lines_n) {

	char **lines;

	// Apri il file testuale in lettura
	FILE *file = fopen(filepath, "r");
	if (file == NULL) {
		puts("Error opening the file");
		exit(EXIT_FAILURE);
	}

	// Alloca l'array di puntatori
	lines = (char **)malloc(lines_n * sizeof(char *));

	// Leggi ogni riga 
	for (int i = 0; i < lines_n; ++i) {

		const int bufflen = ROW_MAX_LEN + 1;
		char *line = (char *)malloc(bufflen * sizeof(char));

		char *ret = fgets(line, bufflen, file);
		lines[i] = line;

		// Err?
		if (ret == NULL) {
			puts("Error reading the file");
			exit(EXIT_FAILURE);
		}
	}

	// Opzionale! Libera spazio inutilizzato
	for (int i = 0; i < lines_n; ++i) {
		int len = my_strlen(lines[i]);
		lines[i] = (char *)realloc(lines[i], len + 1);
	}

	return lines;
}


/***************************************
* Calcola la lunghezza di una stringa. *
***************************************/
int my_strlen(const char *str) {
	int i = 0;
	while (str[i] != '\0') ++i;
	return i;
}