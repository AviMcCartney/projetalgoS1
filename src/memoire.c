#include "memoire.h"
#include <stdlib.h>

void *allouer_malloc(int n)
{
    void *pointeur;

    pointeur = malloc(n);

    if (pointeur == NULL)
    {
        exit(EXIT_FAILURE);
    }

    return pointeur;
}