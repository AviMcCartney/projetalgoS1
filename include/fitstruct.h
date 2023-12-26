#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include "header.h"

#ifndef FITSTRUCT_H
#define FITSTRUCT_H

typedef struct FitStruct
{
    uint16_t *data;
    Header header_fichier;
} FitStruct;

struct FitStruct construct_fitstruct(FILE *fichier);
#endif // FITSTRUCT_H