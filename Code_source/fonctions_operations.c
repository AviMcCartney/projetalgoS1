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
#include <stdint.h>
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
        if (strncmp(line, "BZERO   = ", 10) == 0)
            sscanf(line, "BZERO   = %d", &entete.BZERO);
        if (strncmp(line, "BSCALE  = ", 10) == 0)
            sscanf(line, "BSCALE  = %d", &entete.BSCALE);
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
    printf("\nBITPIX = %d, NAXIS = %d, NAXIS1 = %d, NAXIS2= %d, NAXIS3= %d, BZERO = %d, BSCALE = %d,  DATE= %s", entete.BITPIX, entete.NAXIS, entete.NAXIS1, entete.NAXIS2, entete.NAXIS3, entete.BZERO, entete.BSCALE, entete.DATE);
    // Ferme le fichier
    fclose(fichier);
    printf("\n");
    return entete;
}

/**
 * @brief Permet de renseigner les valeurs réelles d'un fichier FIT dans un CSV
 *
 * @param chemin_fichier
 * @param chemin_fichier_csv
 */
struct header conversion_csv(char *chemin_fichier, char *chemin_fichier_csv)
{
    FILE *fichier = fopen(chemin_fichier, "rb");
    FILE *fichier_csv = fopen(chemin_fichier_csv, "w");

    if (fichier == NULL || fichier_csv == NULL)
    {
        perror("Erreur lors de l'ouverture des fichiers");
        exit(EXIT_FAILURE);
    }

    struct header entete2 = read_sortie(chemin_fichier);

    // Calcul du BITPIX
    int base = 2;
    int exposant = entete2.BITPIX;
    int pixel = pow(base, exposant) - 1;
    printf("\n Un pixel à comme valeur maximale : %d\n", pixel);

    // Positionne le pointeur à la suite du header pour ne pas le retraiter
    fseek(fichier, 2880, SEEK_SET);

    entete2.DATA = (int **)malloc(sizeof(int *) * entete2.NAXIS2); // A free plus tard dans le main
    for (int i = 0; i < entete2.NAXIS2; i++)
    {
        entete2.DATA[i] = malloc(sizeof(int *) * entete2.NAXIS1);
    }

    // Traitement en fonction de BITPIX
    if (entete2.BITPIX == 16)
    {
        uint16_t pixel;
        for (int i = 0; i < entete2.NAXIS2; i++)
        {
            for (int j = 0; j < entete2.NAXIS1; j++)
            {
                if (fread(&pixel, sizeof(pixel), 1, fichier) == 1)
                {
                    pixel = (pixel >> 8) | (pixel << 8);
                    entete2.DATA[i][j] = pixel;
                    fprintf(fichier_csv, "%hd;", entete2.BZERO + entete2.BSCALE * pixel);
                }
                if (j == entete2.NAXIS1 - 1)
                {
                    fprintf(fichier_csv, "\n");
                }
            }
        }

        fprintf(fichier_csv, "\n");
        fclose(fichier);
        fclose(fichier_csv);
        return entete2;
    }
}

/**
 * @brief
 *
 * @param chemin_fichier1
 * @param chemin_fichier2
 * @param chemin_fichier_sortie
 */
void somme_image(const char *chemin_fichier1, const char *chemin_fichier2, const char *chemin_fichier_sortie)
{
    FILE *fichier1 = fopen(chemin_fichier1, "rb");
    FILE *fichier2 = fopen(chemin_fichier2, "rb");
    FILE *fichier_sortie = fopen(chemin_fichier_sortie, "wb");

    if (fichier1 == NULL || fichier2 == NULL || fichier_sortie == NULL)
    {
        perror("Erreur lors de l'ouverture des fichiers");
        exit(EXIT_FAILURE);
    }

    struct header entete1 = read_sortie(chemin_fichier1);
    struct header entete2 = read_sortie(chemin_fichier2);

    // Vérifie que les dimensions des images sont les mêmes
    if (entete1.NAXIS1 != entete2.NAXIS1 || entete1.NAXIS2 != entete2.NAXIS2)
    {
        fprintf(stderr, "Les dimensions des images ne correspondent pas.\n");
        fclose(fichier1);
        fclose(fichier2);
        fclose(fichier_sortie);
        exit(EXIT_FAILURE);
    }

    // Positionne le pointeur des fichiers après leur header
    fseek(fichier1, 2880, SEEK_SET);
    fseek(fichier2, 2880, SEEK_SET);

    uint16_t pixel1, pixel2, pixel_somme;
    for (int i = 0; i < entete1.NAXIS2; i++)
    {
        for (int j = 0; j < entete1.NAXIS1; j++)
        {
            fread(&pixel1, sizeof(uint16_t), 1, fichier1);
            fread(&pixel2, sizeof(uint16_t), 1, fichier2);

            pixel_somme = pixel1 + pixel2;

            fwrite(&pixel_somme, sizeof(uint16_t), 1, fichier_sortie);
        }
    }

    fclose(fichier1);
    fclose(fichier2);
    fclose(fichier_sortie);
}