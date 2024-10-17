#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void filter_write(char * message, FILE * file)
{
    if(*message == '\0')
    {
        return;
    }
    else if(*message>='a' && *message<='z')
    {
        fputc(*message, file);
    }
    filter_write(message+1, file);
}

bool same_content(FILE *f1, FILE *f2)
{
    char read_char_1 = fgetc(f1);
    char read_char_2 = fgetc(f2);
    
    if(read_char_1 == EOF && read_char_2 == EOF)
    {
        return true;
    }
    else if(
        (read_char_1 == EOF && read_char_2 != EOF)
        ||
        (read_char_1 != EOF && read_char_2 == EOF))
    {
        return false;
    }
    else
    {
        return (read_char_1 == read_char_2) && same_content(f1, f2);
    }
}