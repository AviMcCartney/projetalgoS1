#include "menu.h"

void menu()
{
    FILE *mon_fichier1 = ouvrir_fichier("Images//lights/r_lights_00001.fit", "rb");
    FILE *mon_fichier2 = ouvrir_fichier("Images//lights/r_lights_00002.fit", "rb");

    printf("\nINFORMATIONS HEADER 1ère IMAGE:");
    FitStruct maFitStruct1 = construct_fitstruct(mon_fichier1);
    printf("\nINFORMATIONS HEADER 2nde IMAGE:");
    FitStruct maFitStruct2 = construct_fitstruct(mon_fichier2);

    FitStruct fitStructs[] = {maFitStruct1, maFitStruct2};

    int choix;
    int continuer = 1;

    while (continuer)
    {
        printf("\n===== Menu =====\n");
        printf("1. Faire le CSV de la 1ère image\n");
        printf("2. Faire le CSV de la 2ème image\n");
        printf("3. Somme d'images\n");
        printf("4. Moyenne d'images\n");
        printf("5. Division d'images\n");
        printf("6. Soustraction d'images\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            // Afficher les headers de la première image
            ecrire_pixels_csv(maFitStruct1, "image1.csv");

            break;
        case 2:
            // Afficher les headers de la deuxième image
            ecrire_pixels_csv(maFitStruct2, "image2.csv");

            break;
        case 3:
            // Somme d'images
            FitStruct resultat_somme = somme_image(fitStructs, 2);
            afficher_premieres_valeurs(resultat_somme, 10);
            ecrire_fit_file(resultat_somme, "somme.fit");

            break;
        case 4:
            // Moyenne d'images
            FitStruct resultat_moyenne = moyenne_image(fitStructs, 2);
            afficher_premieres_valeurs(resultat_moyenne, 10);
            ecrire_fit_file(resultat_moyenne, "moyenne.fit");

            break;
        case 5:
            // Division d'images
            FitStruct resultat_division = diviser_image(maFitStruct1, maFitStruct2);
            afficher_premieres_valeurs(resultat_division, 10);
            ecrire_fit_file(resultat_division, "division.fit");

            break;
        case 6:
            // Soustraction d'images
            FitStruct resultat_soustraction = soustraire_image(maFitStruct1, maFitStruct2);
            afficher_premieres_valeurs(resultat_soustraction, 10);
            ecrire_fit_file(resultat_soustraction, "soustraction.fit");

            break;
        case 0:
            // Quitter
            continuer = 0;

            break;
        default:
            printf("Choix non valide. Veuillez réessayer.\n");
        }
    }

    fclose(mon_fichier1);
    fclose(mon_fichier2);
}