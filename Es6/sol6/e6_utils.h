#include <stdio.h>
#include <stdlib.h>

#define ROW_MAX_LEN 80
#define TEST_FILE1 "testfile1.txt"
#define TEST_FILE2 "testfile2.txt"
#define TEST_FILE3 "testfile3.txt"


char ** read_lines(const char filepath[], int lines_n);
int my_strlen(const char *str);