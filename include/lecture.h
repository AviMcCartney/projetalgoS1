/**
 * @file lecture.h
 * @author Alexandre, Célian, Sophie
 * @brief Fichier lecture.h contenant l'ensemble des prototypes et des déclarations pour les lecture de fichier et de header
 * @version 0.1
 * @date 2023-12-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef LECTURE_H
#define LECTURE_H
#include <stdio.h>
#include <stdint.h>
#include "fitstruct.h"

char *lire_donnees_header(FILE *fichier);

FILE *ouvrir_fichier(char *chemin_fichier, char *option);
uint16_t *lire_donnees_image(FILE *fichier, int naxis1, int naxis2);

#endif // LECTURE_H