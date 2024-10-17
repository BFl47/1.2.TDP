#include "insf_scl.h"

Insieme init(int *arr, int n);                          //8.1
void print(Insieme s);                                  //8.2
void print_aux(IteratoreInsieme it);
Insieme copy(Insieme s);                                //8.3
Insieme copy_aux(IteratoreInsieme it);
int size(Insieme s);                                    //8.4
int size_aux(IteratoreInsieme it);
bool subset(Insieme a, Insieme b);                      //8.5
bool subset_aux(IteratoreInsieme it, Insieme ins);
bool equal(Insieme a, Insieme b);                       //8.6
Insieme intersection(Insieme a, Insieme b);             //8.7
Insieme iter_aux(IteratoreInsieme it, Insieme b);
Insieme un(Insieme a, Insieme b);                       //8.8
Insieme un_aux(IteratoreInsieme it, Insieme ins);