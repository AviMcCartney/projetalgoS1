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

void read_sortie(const char *chemin_fichier)
{
    FILE *fichier;
    unsigned char buffer[2880]; // Buffer pour stocker les données du header
    size_t bytes_lus;
    int cpt;
    int line[cpt];
    struct header bebou;

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
            sscanf(line, "NAXIS   = %d", &bebou.NAXIS);
        if (strncmp(line, "NAXIS1  = ", 10) == 0)
            sscanf(line, "NAXIS1  = %d", &bebou.NAXIS1);
        if (strncmp(line, "NAXIS2  = ", 10) == 0)
            sscanf(line, "NAXIS2  = %d", &bebou.NAXIS2);
        if (strncmp(line, "NAXIS3  = ", 10) == 0)
            sscanf(line, "NAXIS3  = %d", &bebou.NAXIS3);
        if (strncmp(line, "EXTEND  = ", 10) == 0)
            sscanf(line, "EXTEND  = %s", &bebou.EXTEND);
        if (strncmp(line, "BITPIX  = ", 10) == 0)
            sscanf(line, "BITPIX  = %d", &bebou.BITPIX);
        if (strncmp(line, "DATE    = ", 10) == 0)
            sscanf(line, "DATE    = %s", &bebou.DATE);
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
    printf("\nNAXIS = %d, NAXIS1 = %d, NAXIS2= %d, NAXIS3= %d, EXTEND = %s, BITPIX = %d, DATE= %s", bebou.NAXIS, bebou.NAXIS1, bebou.NAXIS2, bebou.NAXIS3, bebou.EXTEND, bebou.BITPIX, bebou.DATE);

    printf("\n");

    // Ferme le fichier
    fclose(fichier);
}

// void menu(){
//     switch (int choix)
//     {
//     case choix==1:
//         read_sortie(kdsjdshsdj)
//         break;

//     default:
//         break;
//     }
// }