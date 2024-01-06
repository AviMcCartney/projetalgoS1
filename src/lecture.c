/**
 * @file lecture.c
 * @author Alexandre, Célian, Sophie
 * @brief Fichier lecture.c contenant l'ensemble des fonctions pour la lecture de fichier et de header
 * @version 0.1
 * @date 2023-12-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "lecture.h"
#include "memoire.h"
#include "header.h"
#include "fitstruct.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Retourne les données du header du fichier
 *
 * @param fichier Le chemin du fichier .fit pour lequel on veut lire les données du header
 * @return char*
 */
char *lire_donnees_header(FILE *fichier)
{
    char *buffer = (char *)allouer_malloc(sizeof(char) * NB_LIGNES_HEADER * LONGUEUR_LIGNES_HEADER);

    fread(buffer, OCTETS_HEADER, 1, fichier);

    return buffer;
}

/**
 * @brief Ouvre le fichier passé en paramètre avec son option
 *
 * @param chemin_fichier
 * @param option
 * @return FILE*
 */
FILE *ouvrir_fichier(char *chemin_fichier, char *option)
{
    FILE *mon_fichier = fopen(chemin_fichier, option);

    if (mon_fichier == NULL)
    {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", chemin_fichier);
        exit(EXIT_FAILURE);
    }
    return mon_fichier;
}

/**
 * @brief Lit les données brutes de l'images en format big endian
 *
 * @param fichier Le chemin du fichier .fit pour lequel on veut lire les données
 * @param naxis1  La valeur NAXIS1 de ce fichier
 * @param naxis2  La valeur NAXIS2 de ce fichier
 * @return uint16_t*
 */
int16_t *lire_donnees_image(FILE *fichier, int naxis1, int naxis2)
{
    fseek(fichier, 2880, SEEK_SET);
    size_t total_pixels = naxis1 * naxis2 * 2;
    int16_t *buffer = (int16_t *)allouer_malloc(total_pixels * sizeof(int16_t));

    uint16_t pixel;
    for (size_t i = 0; i < total_pixels; i++)
    {
        if (fread(&pixel, sizeof(pixel), 1, fichier) == 1)
        {
            pixel = (pixel >> 8) | (pixel << 8);
            buffer[i] = pixel;
        }
    }

    return buffer;
}