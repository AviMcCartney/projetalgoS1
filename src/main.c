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
#include "menu.h"

int main()
{
    //************** DECLARATION ET OUVERTURE DES FICHIERS **************
    // FILE *mon_fichier = ouvrir_fichier("Images//lights/r_lights_00001.fit", "rb");
    // FILE *mon_fichier2 = ouvrir_fichier("Images//lights/r_lights_00002.fit", "rb");

    // //************** CONSTRUCTION DES HEADERS DES FICHIERS **************
    // // construct_header(mon_fichier);

    // //************** CONSTRUCTION DES FitStruct DES FICHIERS **************
    // FitStruct maFitStruct = construct_fitstruct(mon_fichier);
    // FitStruct maFitStruct2 = construct_fitstruct(mon_fichier2);
    // FitStruct resultat_somme, resultat_moyenne, resultat_division, resultat_soustraction;

    // //************** DECLARATION LISTE DE FITSTRUCT **************
    // FitStruct fitStructs[] = {maFitStruct, maFitStruct2};

    //************** TEST HEADERS IDENTIQUE DE 2 FICHIERS **************
    // if (headers_compatible(fitStructs, 2))
    // {
    //     printf("Les headers sont compatibles.\n");
    // }
    // else
    // {
    //     printf("Les headers ne sont pas compatibles.\n");
    // }

    //************** TEST ELABORATION .CSV **************
    // ecrire_pixels_csv(maFitStruct, "test.csv");

    //************** AFFICHAGE DES PREMIERS PIXELS DES IMAGES **************
    // printf("\n**********IMAGE N°1************\n");
    // afficher_premieres_valeurs(maFitStruct, 10);

    // printf("\n**********IMAGE N°2************\n");
    // afficher_premieres_valeurs(maFitStruct2, 10);
    // //************** TEST OPERATIONS **************
    // // Tester la somme
    // resultat_somme = somme_image(fitStructs, 2);
    // printf("\n**********SOMME************\n");
    // afficher_premieres_valeurs(resultat_somme, 10);

    // // Tester la moyenne
    // resultat_moyenne = moyenne_image(fitStructs, 2);
    // printf("\n**********MOYENNE************\n");
    // afficher_premieres_valeurs(resultat_moyenne, 10);

    // // Tester la division
    // resultat_division = diviser_image(maFitStruct, maFitStruct2);
    // printf("\n**********DIVISON************\n");
    // afficher_premieres_valeurs(resultat_division, 10);

    // // Tester la soustraction
    // resultat_soustraction = soustraire_image(maFitStruct, maFitStruct2);
    // printf("\n**********SOUSTRACTION************\n");
    // afficher_premieres_valeurs(resultat_soustraction, 10);

    // fclose(mon_fichier);
    // fclose(mon_fichier2);

    //************** CREER .FIT A PARTIR D'UNE FITSTRUCT **************
    // FILE *mon_fichier = ouvrir_fichier("Images//lights/r_lights_00001.fit", "rb");
    // FitStruct maFitStruct = construct_fitstruct(mon_fichier);
    // ecrire_fit_file(maFitStruct, "nouveau_fichier.fit");

    menu();

    return 0;
}
