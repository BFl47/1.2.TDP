#include "funzioni.h"

void mat_scan(Mat*m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("m[%d][%d]: ", i, j);
            scanf("%f", &(m->rows_pt[i][j]));
        }
    }
}

//5.1
Mat* mat_alloc(int rows, int cols) {
    Mat* ris = (Mat*) malloc(sizeof(Mat));
    ris->rows = rows;
    ris->cols = cols;
    ris->rows_pt = (float**) malloc(ris->rows * sizeof(float*));
    for (int i = 0; i < ris->rows; i++) 
        ris->rows_pt[i] = (float*) malloc(ris->cols * sizeof(float));
    return ris;
}

//5.2
void mat_free(Mat *m) {
    for (int i = 0; i < m->rows; i++)
        free(m->rows_pt[i]);
    free(m->rows_pt);
    free(m);
}

//5.3
void mat_print(Mat *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) 
            printf("%f ", m->rows_pt[i][j]);
        printf("\n");
    }
}

//5.11
Mat* mat_read(const char *filename) {
    FILE* f = fopen(filename, "r");
    int rows, cols;
    fscanf(f, "%d%d", &rows, &cols);
    Mat* r = mat_alloc(rows, cols);
    for (int i = 0; i < r->rows; i++) {
        for (int j = 0; j < r->cols; j++)
            fscanf(f, "%f", &(r->rows_pt[i][j]));
    }
    fclose(f);
    return r;
}

//5.12
void mat_write(const char *filename, Mat *m) {
    FILE* f = fopen(filename, "w");
    fprintf(f, "%d %d\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            fprintf(f, "%f ", m->rows_pt[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    
}