/**
 * @file ecriture.h
 * @author Alexandre, Célian, Sophie
 * @brief Fichier ecriture.h contenant l'ensemble des prototypes et des déclarations pour les procédures d'écriture.
 * @version 0.1
 * @date 2024-01-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef ECRITURE_H
#define ECRITURE_H
#include "fitstruct.h"
#include "lecture.h"

void ecrire_pixels_csv(FitStruct fitStruct, char *nom_fichier_csv);
void ecrire_fit_file(FitStruct fitStruct, char *filename);

#endif // ECRITURE_H