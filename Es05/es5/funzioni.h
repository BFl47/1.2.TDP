#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
int rows;
int cols;
float **rows_pt;
} Mat;

void mat_rand(Mat* m);
void mat_scan(Mat* m);

Mat* mat_alloc(int rows, int cols);                     //5.1
void mat_free(Mat *m);                                  //5.2
void mat_print(Mat *m);                                 //5.3
Mat * mat_clone(Mat *m);                                //5.4
bool mat_is_symmetric(Mat *m);                          //5.5
void mat_normalize_rows(Mat *m);                        //5.6
Mat* mat_sum(Mat *m1, Mat *m2);                         //5.7
Mat* mat_product(Mat *m1, Mat *m2);                     //5.8

void sort_strings(char **array);                        //5.9