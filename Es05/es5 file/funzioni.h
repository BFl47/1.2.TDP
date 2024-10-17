#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
int rows;
int cols;
float **rows_pt;
} Mat;

void mat_scan(Mat* m);

Mat* mat_alloc(int rows, int cols);                     //5.1
void mat_free(Mat *m);                                  //5.2
void mat_print(Mat *m);                                 //5.3

Mat* mat_read(const char *filename);                    //5.11
void mat_write(const char *filename, Mat *m);           //5.12