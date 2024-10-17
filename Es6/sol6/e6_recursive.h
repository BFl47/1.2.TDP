#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void vec_print(float v[], int dim);

void copy(char *dest, char *s);
void concat(char *dest, char *src);
float product(float a[], int n);

bool is_lowercase(char *s);

float vec_dot_aux(float *v1, float *v2, int n, int i);
float vec_dot(float *v1, float *v2, int n);

void to_uppercase(char *s);
bool is_lowercase(char *s);
void vec_integral(float *v, int n);

void vec_integral_aux(float *v, int n, int i, float sum_till_now);
int char_position(char *s, char ch);
int char_position_aux(char *s, char ch, int i);

int length(char *s);