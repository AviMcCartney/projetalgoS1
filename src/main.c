/**
 * @file main.c
 * @author Alexandre, Célian, Sophie
 * @brief Fichier main.c contenant l'ensemble de nos procédures de tests
 * @version 0.1
 * @date 2023-12-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "lecture.h"
#include "fitstruct.h"
#include "ecriture.h"

int main()
{
    FILE *mon_fichier = ouvrir_fichier("Images/r_lights_00004.fit", "rb");

    // construct_header(mon_fichier);

    FitStruct maFitStruct = construct_fitstruct(mon_fichier);

    // afficher_tous_les_pixels(maFitStruct);

    // free(maFitStruct.data);
    ecrire_pixels_csv(maFitStruct, "test.csv");
    fclose(mon_fichier);

    return 0;
}
