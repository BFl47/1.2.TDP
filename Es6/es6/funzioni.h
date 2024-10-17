#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void vec_print(float* v, int n);

float product(float vec[], int n);                                  //6.1
void vec_integral(float* v, int n);                                 //6.2
void vec_integral_aux(float* v, int n, int somma);                  

int length(char * s);                                               //6.3
int char_position(char* s, char ch);                                //6.4
int char_position_aux(char* s, char ch, int i);
bool is_lowercase(char *s);                                         //6.5
void to_uppercase(char *s);                                         //6.6
void copy(char * dest, char * src);                                 //6.7
void concat(char * dest, const char * src);                         //6.8
void filter_write(char * message, FILE * file);                     //6.9
bool same_content(FILE *f1, FILE *f2);                              //6.10