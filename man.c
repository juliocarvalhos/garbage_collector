#include <stdio.h>
#include <stdlib.h>
#include "contref.h"

int main(int argc, char const *argv[])
{
    
    int *v = malloc2(sizeof(int));
    *v = 10;
    int *w = malloc2(sizeof(int));
    *w = 20;
    atrib2(&v,w);
    char *c = malloc2(sizeof(char));
    *c='Z';
    atrib2(&w,NULL);
    print();
    dump();
    return 0;
}
