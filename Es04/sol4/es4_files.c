
#include <stdio.h>
#include <stdlib.h>

#define ROW_MAX_LEN 80
#define TEST_FILE1 "testfile1.txt"


char ** read_lines(const char filepath[], int *lines_n);

int my_strlen(const char *str);


// Tests
int main(void) {

	int lines_n;
	char **lines = read_lines(TEST_FILE1, &lines_n);

	for (int i = 0; i < lines_n; ++i) {
		printf("%s", lines[i]);
	}
	puts("");

	// Free
	for (int i = 0; i < lines_n; ++i) {
		free(lines[i]);
	}
	free(lines);
}


// Legge righe da file.
char ** read_lines(const char filepath[], int *lines_n) {

	char **lines;

	// Apri il file testuale in lettura
	FILE *file = fopen(filepath, "r");
	if (file == NULL) {
		puts("Error opening the file");
		exit(EXIT_FAILURE);
	}

	// Leggi il numero di righe
	fscanf(file, "%d", lines_n);  // assuming lines_n correct
	fgetc(file);  // consuma il newline

	// Alloca l'array di puntatori
	lines = (char **)malloc(*lines_n * sizeof(char *));

	// Leggi ogni riga 
	for (int i = 0; i < *lines_n; ++i) {

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
	for (int i = 0; i < *lines_n; ++i) {
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
