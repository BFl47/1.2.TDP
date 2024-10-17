
#include <stdio.h>
#include <stdlib.h>


void print_chars(const char s[], const int idxs[], int dim);
char * select_chars(const char s[], const int idxs[], int dim);
char * invert_string(const char s[]);
char * mocking_spongebob(const char s[], int step);
char * capitalizer(const char s[]);

int my_strlen(const char *str);


int main(void)
{

	// Test print chars
	const char s[] = "puntatore";
	const int idxs[] = {1, 3, 5, 11};
	printf("print_chars..\n");
	print_chars(s, idxs, 4);
	printf("\n\n");

	// Test select chars
	printf("select_chars..\n");
	char *char_selected = select_chars(s, idxs, 4);
	printf("%s", char_selected);
	printf("\n\n");

	printf("invert_string...\n");
	char *char_invertito = invert_string(s);
	printf("%s", char_invertito);
	printf("\n\n");

	printf("mocking_spongebob...\n");
	char s4[] = "Stai imparando TDP?";
	int step = 2;
	char *char_mocking = mocking_spongebob(s4, step);
	printf("%s", char_mocking);
	printf("\n\n");

	printf("capitalizer...\n");
	char *char_maiuscolo = capitalizer(char_mocking);
	printf("%s", char_maiuscolo);
	printf("\n");

	free(char_selected);
	free(char_invertito);
	free(char_mocking);
	free(char_maiuscolo);
}


void print_chars(const char s[], const int idxs[], int dim)
{

	int str_dim = my_strlen(s);
	for (int it = 0; it < dim; it++)
	{
		int index = idxs[it];

		if (0 <= index && index < str_dim)
		{
			putchar(s[index]);
		}
	}
}


char *select_chars(const char s[], const int idxs[], int dim)
{

	int str_dim = my_strlen(s);
	char *output_string = (char *)malloc((dim + 1) * sizeof(char));
	int it2 = 0;

	for (int it = 0; it < dim; it++)
	{
		int index = idxs[it];
		if (0 <= index && index < str_dim)
		{
			output_string[it2] = s[index];
			it2++;
		}
		output_string[it2] = '\0';
	}

	return output_string;
}


char * invert_string(const char s[])
{

	int str_dim = my_strlen(s);
	char *output_string = (char *)malloc((str_dim + 1) * sizeof(char));

	for (int it = 0; it < str_dim; it++) {
		*(output_string + it) = s[str_dim - it - 1];
	}

	*(output_string + str_dim) = '\0';

	return output_string;
}

char * mocking_spongebob(const char s[], int step)
{
	const int to_upper = 'A' - 'a';

	int str_dim = my_strlen(s);
	char *res = (char *)malloc((str_dim + 1) * sizeof(char));

	for (int it = 0; it < str_dim; it++)
	{
		char val = s[it];
		res[it] = val;

		if (it % step == 0 && 'a' <= val && val <= 'z')
		{
			res[it] = val + to_upper;
		}
	}

	return res;
}



char * capitalizer(const char s[])
{

	int str_dim = my_strlen(s);
	char *output_string = (char *)malloc((str_dim + 1) * sizeof(char));
	for (int it = 0; it < str_dim; it++)
	{
		output_string[it] = s[it];

		if ((it == 0) || s[it - 1] == ' ')
		{

			if (s[it] >= 'a' && s[it] <= 'z')
			{
				output_string[it] = s[it] - 'a' + 'A';
			}
		}
		else
		{
			if (s[it] >= 'A' && s[it] <= 'Z')
			{
				output_string[it] = s[it] - 'A' + 'a';
			}
		}
	}

	output_string[str_dim] = '\0';
	return output_string;
}


int my_strlen(const char *str)
{
	int i = 0;
	while (str[i] != '\0') ++i;
	return i;
}
