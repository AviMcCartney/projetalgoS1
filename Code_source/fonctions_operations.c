/**
 * @file fonctions_operations.c
 * @author Alexandre, Célian, Sophie
 * @brief Fichier contenant la définition de l'ensemble de nos fonctions
 * @version 0.1
 * @date 2023-12-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "prototype.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Afficher et mettre en forme le header d'un fichier FITS
 *
 * @param chemin_fichier
 */
struct header read_sortie(char *chemin_fichier)
{
    FILE *fichier;
    unsigned char buffer[2880]; // Buffer pour stocker les données du header
    size_t bytes_lus;
    int cpt;
    int line[cpt];
    struct header entete;

    // Ouvre le fichier en mode lecture binaire
    fichier = fopen(chemin_fichier, "rb");
    if (fichier == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lit les 2880 premiers octets du fichier
    bytes_lus = fread(buffer, 1, sizeof(buffer), fichier);
    if (bytes_lus < sizeof(buffer))
    {
        if (feof(fichier))
        {
            printf("Fin de fichier atteinte avant de lire 2880 octets.\n");
        }
        else if (ferror(fichier))
        {
            perror("Erreur lors de la lecture du fichier");
        }
        fclose(fichier);
        exit(EXIT_FAILURE);
    }

    // Affiche les octets lus en ASCII
    for (size_t i = 0; i < sizeof(buffer); i++)
    {
        char line[81];
        strncpy(line, (char *)&buffer[i], 80);
        line[80] = '\0';

        if (strncmp(line, "NAXIS   = ", 10) == 0)
            sscanf(line, "NAXIS   = %d", &entete.NAXIS);
        if (strncmp(line, "NAXIS1  = ", 10) == 0)
            sscanf(line, "NAXIS1  = %d", &entete.NAXIS1);
        if (strncmp(line, "NAXIS2  = ", 10) == 0)
            sscanf(line, "NAXIS2  = %d", &entete.NAXIS2);
        if (strncmp(line, "NAXIS3  = ", 10) == 0)
            sscanf(line, "NAXIS3  = %d", &entete.NAXIS3);
        if (strncmp(line, "EXTEND  = ", 10) == 0)
            sscanf(line, "EXTEND  = %s", entete.EXTEND);
        if (strncmp(line, "BITPIX  = ", 10) == 0)
            sscanf(line, "BITPIX  = %d", &entete.BITPIX);
        if (strncmp(line, "DATE    = ", 10) == 0)
            sscanf(line, "DATE    = %s", entete.DATE);
        if (cpt > 79)
        {
            printf("\n");
            cpt = 0;
        }
        if (buffer[i] >= 32 && buffer[i] <= 126)
        {
            // Affiche le caractère ASCII affichable
            printf("%c", buffer[i]);
        }
        else
        {
            // Remplace les caractères affichables par un point
            printf(".");
        }

        cpt++;
    }
    printf("\n*****************************************");
    printf("\nLes données importantes du header à retenir sont :");
    printf("\nNAXIS = %d, NAXIS1 = %d, NAXIS2= %d, NAXIS3= %d, EXTEND = %s, BITPIX = %d, DATE= %s", entete.NAXIS, entete.NAXIS1, entete.NAXIS2, entete.NAXIS3, entete.EXTEND, entete.BITPIX, entete.DATE);
    // Ferme le fichier
    fclose(fichier);
    printf("\n");
    return entete;
}

void conversion_csv(char *chemin_fichier, char *chemin_fichier_csv)
{
    FILE *fichier = fopen(chemin_fichier, "rb");
    FILE *fichier_csv = fopen(chemin_fichier_csv, "w");

    if (fichier == NULL || fichier_csv == NULL)
    {
        perror("Erreur lors de l'ouverture des fichiers");
        exit(EXIT_FAILURE);
    }

    struct header entete2 = read_sortie(chemin_fichier);
    int base = 2;
    int exposant = entete2.BITPIX;
    int pixel = pow(base, exposant);
    printf("\n%d", pixel);
    fseek(fichier, 2880, SEEK_SET);

    // for (int i = 0; i < entete2.NAXIS2; i++)
    // {
    //     for (int j = 0; j < entete2.NAXIS1; j++)
    //     {
    //     }
    //     else
    //     {
    //         perror("Erreur lors de la lecture des données de l'image");
    //         fclose(fichier);
    //         fclose(fichier_csv);
    //         exit(EXIT_FAILURE);
    //     }
    // }
    // fprintf(fichier_csv, "\n");

    // fclose(fichier);
    // fclose(fichier_csv);
}