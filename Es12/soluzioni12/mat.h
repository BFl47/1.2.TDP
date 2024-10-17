#pragma once

// Struttura tipo matrice
typedef struct {
  int rows;
  int cols;
  char **mat;
} CharMat;

typedef struct {
  int rows;
  int cols;
  float **mat;
} FloatMat;

enum Symbols {
  HEAD = 'X',
  BORDER = '#',
  APPLE = 'o',
  EMPTY = ' ',
};

enum Direction {
  UP = 'w',
  DOWN = 's',
  RIGHT = 'd',
  LEFT = 'a'
};

// Operazioni su matrici
FloatMat * Mat_alloc_float(int rows, int cols);
FloatMat * FloatMat_square_alloc(int n);
void FloatMat_print(FloatMat *m);
void FloatMat_free(FloatMat *m);

CharMat * CharMat_alloc(int rows, int cols);
void CharMat_print(CharMat *m);
void CharMat_free(CharMat *m);

// Aux
bool mat_is_equal(const CharMat *m1, const CharMat *m2);
