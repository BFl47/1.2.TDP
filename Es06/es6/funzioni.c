#include "funzioni.h"

void vec_print(float* v, int n) {
    if (n == 0)
        printf("\n");
    else {
        printf("%f ", *v);
        vec_print(v+1, n-1);
    }
}

//6.1
float product(float vec[], int n) {
    if (n == 0)
        return 1;
    return *vec * product(vec+1, n-1);
}

//6.2  0 1 3 6
void vec_integral(float* v, int n) {
    vec_integral_aux(v, n, 0);
}

void vec_integral_aux(float* v, int n, int somma) {
    if (n == 0)
        return;
    int temp = *v;
    *v = somma;
    somma += temp;
    vec_integral_aux(v+1, n-1, somma);
}

//6.3
int length(char * s) {
    if (*s == '\0')
        return 0;
    return 1 + length(s+1);
}

//6.4
int char_position(char* s, char ch) {
    return char_position_aux(s, ch, 0);
}

int char_position_aux(char* s, char ch, int i) {
    if (*s == '\0')
        return -1;
    else if (*s == ch)
        return i;
    else 
        return char_position_aux(s+1, ch, i+1);
}

//6.5
bool is_lowercase(char *s) {
    if (*s == '\0')
        return true;
    else if (*s >= 'a' && *s <= 'z')
        return true && is_lowercase(s+1);
    else 
        return false;
}

//6.6
void to_uppercase(char *s) {
    if (*s == '\0')
        return;
    else if (*s >= 'a' && *s <= 'z') 
        *s -= 32;
    to_uppercase(s+1);
}

//6.7
void copy(char * dest, char * src) {
    if (*src == '\0') {
        *dest = '\0';
        return;
    }
    *dest = *src;
    copy(dest+1, src+1);
}

//6.8
void concat(char * dest, const char * src) {
    if (*src == '\0') {
        return;
    }
    else if (*dest == '\0') {
        *dest = *src;
        *(dest+1) = '\0';
        concat(dest+1, src+1);
    }
    else
        concat(dest+1, src);
}

//6.9
void filter_write(char * message, FILE * file) {
    if (*message == '\0') {
        fprintf(file, "\n");
        return;
    }
    else if (*message >= 'a' && *message <= 'z') 
        fputc(*message, file);
    filter_write(message+1, file);
}

//6.10
bool same_content(FILE *f1, FILE *f2) {
    char e1 = fgetc(f1);
    char e2 = fgetc(f2);
    if (e1 == EOF && e2 == EOF)
        return true;
    else if (e1 == e2)
        return true && same_content(f1, f2);
    return false;
}