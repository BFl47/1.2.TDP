#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "functions.h"

#define N 7


int main()
{
    printf("Random list\n");
    int vec[N] = {1, 2, 3, 4, 5, 6, 7};
    TipoLista list1 = init(vec, N);
    printf("The list is:\n");
    printlist(list1);

    TipoLista dc = doubledCopy(list1);
    printf("doubledCopy result is:\n");

    printlist(dc);

    TipoLista ms = multipleSubset(list1, 3);
    printf("multipleSubset result is:\n");

    printlist(ms);

    TipoLista sl = subList(list1, 3, 6);
    printf("subList [3, 6] result is:\n");
    printlist(sl);

    sl = subList(list1, 3, 9);
    printf("subList [3, 9] result is:\n");
    printlist(sl);

    int vec2[N] = {7, 8, 9, 10, 11, 12};
    TipoLista list2 = init(vec2, N);
    printf("The list2 is:\n");
    printlist(list2);

    TipoLista inter = interleave(list1, list2);
    printf("interleave result is:\n");
    printlist(inter);
}
