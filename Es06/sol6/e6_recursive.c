#include <stdio.h>
#include <stdlib.h>

#include "e6_recursive.h"

void copy(char *dest, char *s)
{

	if (*s == '\0')
	{
		*dest = '\0';
		return;
	}
	else
	{
		*dest = *s;
		return copy(dest + 1, s + 1);
	}
}

void concat(char *dest, char *src)
{

	if (*dest == '\0')
	{
		copy(dest, src);
	}
	else
	{
		return concat(dest + 1, src);
	}
}

float product(float a[], int n)
{

	if (n == 0)
	{
		return 1;
	}
	else
	{
		return a[0] * product(a + 1, n - 1);
	}
}

bool is_lowercase(char *s)
{

	if (*s == '\0')
	{
		return true;
	}
	else if (*s >= 'a' && *s <= 'z')
	{
		return is_lowercase(s + 1);
	}
	else
	{
		return false;
	}
}

float vec_dot_aux(float *v1, float *v2, int n, int i)
{
	if (i == n)
		return 0;
	return *v1 * *v2 + vec_dot_aux(v1 + 1, v2 + 1, n, i + 1);
}

float vec_dot(float *v1, float *v2, int n)
{

	int i = 0;
	return vec_dot_aux(v1, v2, n, i);
}

void to_uppercase(char *s)
{

	if (*s == '\0')
	{
		return;
	}
	else if (*s >= 'a' && *s <= 'z')
	{
		*s = *s - 'a' + 'A';
		return to_uppercase(s + 1);
	}
	else
	{
		return to_uppercase(s + 1);
	}
}

void vec_integral_aux(float *v, int n, int i, float sum_till_now)
{
	if (i == n)
		return;
	*v += sum_till_now;
	i++;
	vec_integral_aux(v + 1, n, i, *v);
}

void vec_integral(float *v, int n)
{
	if (n == 0)
		return;

	int i = 0;
	vec_integral_aux(v, n, i, 0);
}

int char_position_aux(char *s, char ch, int i)
{

	if (*s == '\0')
	{
		return -1;
	}
	else if (*s == ch)
	{
		return i;
	}
	else
	{
		return char_position_aux(s + 1, ch, i + 1);
	}
}

int char_position(char *s, char ch)
{

	int i = 0;
	return char_position_aux(s, ch, i);
}

int length(char *s)
{

	if (*s == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + length(s + 1);
	}
}

void vec_print_aux(float v[], int dim, int pos)
{
	if (pos >= dim)
	{
		return;
	}
	printf("%f ", v[pos]);
	vec_print_aux(v, dim, pos+1);
}

void vec_print(float v[], int dim)
{
	vec_print_aux(v, dim, 0);
}
