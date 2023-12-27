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
#include "operation.h"

int main()
{
    FILE *mon_fichier = ouvrir_fichier("Images//lights/r_lights_00001.fit", "rb");
    FILE *mon_fichier2 = ouvrir_fichier("Images//lights/r_lights_00002.fit", "rb");

    // construct_header(mon_fichier);

    FitStruct maFitStruct = construct_fitstruct(mon_fichier);
    FitStruct maFitStruct2 = construct_fitstruct(mon_fichier2);

    FitStruct fitStructs[] = {maFitStruct, maFitStruct2};

    if (headers_compatible(fitStructs, 2))
    {
        printf("Les headers sont compatibles.\n");
    }
    else
    {
        printf("Les headers ne sont pas compatibles.\n");
    }

    // afficher_tous_les_pixels(maFitStruct);

    // free(maFitStruct.data);
    // ecrire_pixels_csv(maFitStruct, "test.csv");
    fclose(mon_fichier);
    fclose(mon_fichier2);

    return 0;
}
