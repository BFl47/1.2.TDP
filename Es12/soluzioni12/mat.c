#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "mat.h"


CharMat* CharMat_alloc(int rows, int cols) {
  CharMat* m = (CharMat*)malloc(sizeof(CharMat));
  m->rows = rows;
  m->cols = cols;
  m->mat = (char**)malloc(rows * sizeof(char*));
  for(int i = 0; i < m->rows; ++i) {
    m->mat[i] = (char*)malloc(m->cols * sizeof(char));
  }
  return m;
}


void CharMat_print(CharMat *m) {
  for(int r = 0; r < m->rows; ++r) {
    for(int c = 0; c < m->cols; ++c) {
      printf("%c ", m->mat[r][c]);
    }
    printf("\n");
  }
}


void CharMat_free(CharMat *m) {  
  for(int i = 0; i < m->rows; ++i) {
    free(m->mat[i]);
  }
  free(m->mat);
  free(m);
}


FloatMat* FloatMat_alloc(int rows, int cols) {
  FloatMat* m = (FloatMat*)malloc(sizeof(FloatMat));
  m->rows = rows;
  m->cols = cols;
  m->mat = (float**)malloc(rows * sizeof(float*));
  for(int i = 0; i < m->rows; ++i) {
    m->mat[i] = (float*)malloc(m->cols * sizeof(float));
  }
  return m;
}

FloatMat* FloatMat_square_alloc(int n) {
	return FloatMat_alloc(n, n);
}


void FloatMat_free(FloatMat *m) {
	free(*m->mat);
	free(m->mat);
	free(m);
}


void FloatMat_print(FloatMat *m) {

	if (m == NULL) {
		printf("NULL");
		return;
	}

	for (int r = 0; r < m->rows; ++r) {
			for (int c = 0; c < m->cols; ++c) {
					printf("%.2f, ", m->mat[r][c]);
			}
			printf("\n");
	}
}

bool mat_is_equal(const CharMat *m1, const CharMat *m2)
{
    if (m1 == NULL && m2 == NULL) {
        return true;
		}
		if (m1 == NULL || m2 == NULL) {
				return false;
		}
    if (m1->rows != m2->rows) {
        return false;
		}
    if (m1->cols != m2->cols) {
        return false;
		}
    for (int r = 0; r < m1->rows; ++r)
    {
        for (int c = 0; c < m1->cols; ++c)
        {
            if (m1->mat[r][c] != m2->mat[r][c]) {
                return false;
						}
        }
    }
    return true;
}
