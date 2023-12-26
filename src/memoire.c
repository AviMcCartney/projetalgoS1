#include "memoire.h"
#include <stdlib.h>

/**
 * @brief Permet de faire un malloc tout en prenant en compte les erreurs de pointeurs NULL
 *
 * @param n
 * @return void*
 */
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