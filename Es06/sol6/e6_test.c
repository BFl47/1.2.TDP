#include "e6_recursive.h"
#include "e6_files.h"
#include "e6_utils.h"

int main(int argc, char **argv) {
		
	printf("\n");

	//inizializza parametri stringhe
	char s[10] = "ASsfQg\0";
	printf("Data la stringa '%s'\n", s);

	//calcolo lunghezza
	int value = length(s);
	printf("La sua lunghezza e': %d\n\n", value);

	//check carattere
	char ch = 'z';
	int index = char_position(s,ch);
	( index >= 0 ) ? printf("Il carattere %c è presente in indice %d\n", ch, index) : printf("Il carattere %c non è presente\n", ch);
	ch = 'f';
	index = char_position(s,ch);
	( index >= 0 ) ? printf("Il carattere %c è presente in indice %d\n", ch, index) : printf("Il carattere %c non è presente\n", ch);
	printf("\n");

	//check maiuscole
	bool check_minuscole = is_lowercase(s);
	check_minuscole ? printf("Sono tutte minuscole\n") : printf("C'è almeno un carattere maiuscolo\n");
	printf("\n");

	//converti minuscole-maiuscole
	to_uppercase(s);
	printf("Stringa convertita in caratteri maiuscoli: %s\n", s);
	printf("\n");


	int vec_size = 10;
	float vec[vec_size] = {3.1, -2.3, 5.8, 1.4, -0.3, 4.1, 9.1, -3.7, 2.9, -4.9};
	printf("Dato il  vettore:\n");
	vec_print(vec, vec_size);
	vec_integral(vec, vec_size);
	printf("\nIl risultato di integral e':\n");
	vec_print(vec, vec_size);
	printf("\n\n");

	int vecs_size = 5;
	float vec1[vecs_size] = {5.7, 2.3, -3.6, 8.1, -0.1};
	float vec2[vecs_size] = {-5.2, 1.3, -2.1, 1.2, 0.1};
	printf("Dato il  vettore1:\n");
	vec_print(vec1, vec_size);
	printf("\n e il  vettore2:\n");
	vec_print(vec2, vec_size);
	float vec_dot_result = vec_dot(vec1, vec2, vecs_size);
	printf("\nIl risultato del prodotto scalare è: %f\n", vec_dot_result);
	printf("\n");

	float prodotto_res = product(vec1, vecs_size);
	printf("Il prodotto delle componenti del vottore1  è: %f\n", prodotto_res);
	printf("\n");


	char s1[20] = "1234\0";
	char s2[20] = " 5678\0";
	char* s3 = (char*) malloc(20*sizeof(char));

	printf("Copio la stringa '%s' dentro '%s'\n", s2,s3);
	copy(s2, s3);
	printf("Concateno '%s' con '%s'\n", s1,s3);

	concat(s1, s3);
	printf("Stringa concatenata: %s\n", s3);
	printf("\n");


	// FILE //

	//Lettura file testfile1
	printf("Lettura file testfile1.txt\n");
	char **file1_lines = read_lines("testfile1.txt", 5);
	for (int i = 0; i < 5; ++i) {
		printf("%s", file1_lines[i]);
	}
	printf("\n\n");



	//Apertura file testfile2 in scrittura
	FILE *file2 = fopen("testfile2.txt", "w+");
	if (file2 == NULL) {
		puts("Error opening the testfile2.txt");
		exit(EXIT_FAILURE);
	}
	printf("Scrittura delle sole lettere minuscole della seconda riga di testfile1.txt in testfile2.txt\n");
	filter_write(file1_lines[0], file2);
	fclose(file2);

	printf("Lettura file testfile2.txt\n");
	char **file2_lines = read_lines("testfile2.txt", 1);
	for (int i = 0; i < 1; ++i) {
		printf("%s", file2_lines[i]);
	}
	printf("\n\n");



	//Apertura file testfile3 in scrittura
	FILE *file3 = fopen("testfile3.txt", "w+");
	if (file3 == NULL) {
		puts("Error opening the testfile3.txt");
		exit(EXIT_FAILURE);
	}
	printf("Scrittura delle sole lettere minuscole della terza riga di testfile1.txt in testfile3.txt\n");
	filter_write(file1_lines[1], file3);
	fclose(file3);

	printf("Lettura file testfile3.txt\n");
	char **file3_lines = read_lines("testfile3.txt", 1);
	for (int i = 0; i < 1; ++i) {
		printf("%s", file3_lines[i]);
	}
	printf("\n\n");


	//Apertura file testfile4 in scrittura
	FILE *file4 = fopen("testfile4.txt", "w+");
	if (file4 == NULL) {
		puts("Error opening the testfile4.txt");
		exit(EXIT_FAILURE);
	}
	printf("Scrittura della terza riga di testfile1.txt in testfile4.txt\n");
	filter_write(file1_lines[1], file4);
	fclose(file4);

	printf("Lettura file testfile4.txt\n");
	char **file4_lines = read_lines("testfile4.txt", 1);
	for (int i = 0; i < 1; ++i) {
		printf("%s", file4_lines[i]);
	}
	printf("\n\n");
	


	//Apertura di testfile2.txt, testfile3.txt e testfile4.txt in modalità lettura
	file2 = fopen("testfile2.txt", "r");
	file3 = fopen("testfile3.txt", "r");
	file4 = fopen("testfile4.txt", "r");

	//Confronto di testfile2 e testfile3 (dovrebbero essere differenti)
	printf("Confronto di testfile2.txt e testfile3.txt (dovrebbero essere differenti)\n");
	bool file_2_3_equal = same_content(file2, file3);
	printf("testfile2.txt == testfile3.txt: %s\n\n", (file_2_3_equal ? "true" : "false"));
	//printf("testfile2.txt == testfile3.txt: %d\n\n", file_2_3_equal);
	//Change file pointer location
	fseek(file3, 0, SEEK_SET);

	//Confronto di testfile3 e testfile4 (dovrebbero essere identici)
	printf("Confronto di testfile2.txt e testfile3.txt (dovrebbero essere identici)\n");
	bool file_3_4_equal = same_content(file3, file4);
	printf("testfile3.txt == testfile4.txt: %s\n\n", (file_3_4_equal ? "true" : "false"));

	// Free
	for (int i = 0; i < 5; ++i) {
		free(file1_lines[i]);
	}
	free(file1_lines);
	
	for (int i = 0; i < 1; ++i) {
		free(file2_lines[i]);
	}
	free(file2_lines);

	for (int i = 0; i < 1; ++i) {
		free(file3_lines[i]);
	}
	free(file3_lines);

	for (int i = 0; i < 1; ++i) {
		free(file4_lines[i]);
	}
	free(file4_lines);

	fclose(file2);
	fclose(file3);
	fclose(file4);

	return 0;
}