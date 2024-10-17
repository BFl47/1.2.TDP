#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "e6_recursive.h"

void filter_write(char * message, FILE * file);
bool same_content(FILE *f1, FILE *f2);