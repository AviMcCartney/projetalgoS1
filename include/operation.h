/**
 * @file operation.h
 * @author Alexandre, Célian, Sophie
 * @brief Fichier operation.h contenant l'ensemble des prototypes et des déclarations pour les procédures d'opérations.
 * @version 0.1
 * @date 2024-01-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef OPERATION_H
#define OPERATION_H
#include "fitstruct.h"

int headers_compatible(FitStruct *images, int nombre_images);
FitStruct somme_image(FitStruct *images, int nombre_images);
FitStruct moyenne_image(FitStruct *images, int nombre_images);
FitStruct diviser_image(FitStruct images1, FitStruct images2);
FitStruct soustraire_image(FitStruct images1, FitStruct images2);

void afficher_premieres_valeurs(FitStruct somme, int nombre_valeurs);

#endif // OPERATION_H