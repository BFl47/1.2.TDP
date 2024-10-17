#include "funzioni.h"

void mat_rand(Mat* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++)
            m->rows_pt[i][j] = rand() % 10;
    }
}

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

//5.4
Mat * mat_clone(Mat *m) {
    Mat* r = mat_alloc(m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++)
            r->rows_pt[i][j] = m->rows_pt[i][j];
    }
    return r;
}

//5.5
bool mat_is_symmetric(Mat *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (m->rows_pt[i][j] != m->rows_pt[j][i])
                return false;
        }
    }
    return true;
}

//5.6
void mat_normalize_rows(Mat *m) {
    
    for (int i = 0; i < m->rows; i++) {
        int mod = 0;
        for (int j = 0; j < m->cols; j++) 
            mod += pow(m->rows_pt[i][j], 2);
        mod = sqrt(mod);
        for (int j = 0; j < m->cols; j++)
            m->rows_pt[i][j] /= mod;
    }
}

//5.7
Mat* mat_sum(Mat *m1, Mat *m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) 
        return NULL;
    Mat* r = mat_alloc(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++)
            r->rows_pt[i][j] = m1->rows_pt[i][j] + m2->rows_pt[i][j];
    }
    return r;
}

//5.8 m[i, k] * n[k, j]
Mat* mat_product(Mat *m1, Mat *m2) {
    if (m1->cols != m2->rows)
        return NULL;
    Mat* r = mat_alloc(m1->rows, m2-> cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            r->rows_pt[i][j] = 0;
            for (int k = 0; k < m1->cols; k++)
                r->rows_pt[i][j] += m1->rows_pt[i][k] * m2->rows_pt[k][j];
        }
    }
    return r;
}

int len_string(char* s) {
    if (*s == '\0')
        return 0;
    return 1 + len_string(s+1);
}

//5.9
void sort_strings(char **array) {
    int* l = (int*) calloc(10, sizeof(int));
    char** copia = (char**) malloc(10 * sizeof(char*));
    int i = 0;
    while (array[i] != NULL) {
        copia[i] = array[i];
        i++;
    }
    copia[i] = NULL;
    
    i = 0;
    while (array[i] != NULL) {
        l[i] = len_string(array[i]);
        i++;
    }
    
    i = 0;
    int count = 0;
    while (copia[i] != NULL) {
        int max = 0;
        int pos = 0;
        
        for (int j = 0; j < 10; j++) {
            if (l[j] != 0 && l[j] > max) {
                max = l[j];
                pos = j;
            }
        }
        array[count] = copia[pos];
        count++;
        l[pos] = 0;
        i++;
    }
}