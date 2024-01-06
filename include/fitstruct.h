/**
 * @file fitstruct.h
 * @author Alexandre, Célian, Sophie
 * @brief Fichier fitstruct.h contenant l'ensemble des prototypes et des déclarations pour les fitstruct
 * @version 0.1
 * @date 2024-01-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include "header.h"

#ifndef FITSTRUCT_H
#define FITSTRUCT_H

/**
 * @brief FitStruct d'un fichier .fit. Cette structure nous permettra de stocker les informations importantes d'un fichier à savoir les données du header et les données de l'image.
 *
 */
typedef struct FitStruct
{
    int16_t *data;
    Header header_fichier;
} FitStruct;

struct FitStruct construct_fitstruct(FILE *fichier);
#endif // FITSTRUCT_H