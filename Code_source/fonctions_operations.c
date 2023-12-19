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
        if (cpt > 79)
        {
            line[cpt] = '\0'; // Termine la chaîne de caractères

            // Parse la ligne ici
            if (strncmp(line, "BITPIX", 6) == 0)
                sscanf(line, "BITPIX  = %d", &bebou.BITPIX);
            else if (strncmp(line, "NAXIS", 5) == 0)
                sscanf(line, "NAXIS   = %d", &bebou.NAXIS);
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
    printf("\nBITPIX: %d, NAXIS: %d, NAXIS1: %d, NAXIS2: %d\n", bebou.BITPIX, bebou.NAXIS, bebou.NAXIS1, bebou.NAXIS2);

    printf("\n");

    // Ferme le fichier
    fclose(fichier);
}