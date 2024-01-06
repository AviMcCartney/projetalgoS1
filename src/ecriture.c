/**
 * @file ecriture.c
 * @author Alexandre, Célian, Sophie
 * @brief Fichier ecriture.c contenant l'ensemble des fonctions pour la lecture de fichier / données.
 * @version 0.1
 * @date 2024-01-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "ecriture.h"
#include "header.h"
#include "lecture.h"

/**
 * @brief Écrit les valeurs réelles d'une image dans un fichier CSV valeur_réelle = BZERO + BSCALE × valeur_enregistrée. Répond à l'éxigence **PRIM_40**
 *
 * @param fitStruct Structure fitStruct d'une image .fit
 * @param nom_fichier_csv Le chemin du fichier .csv dans lequel on va écrire
 */
void ecrire_pixels_csv(FitStruct fitStruct, char *nom_fichier_csv)
{
    FILE *fichier_csv = ouvrir_fichier(nom_fichier_csv, "w");

    int16_t *pixels = fitStruct.data;
    for (int i = 0; i < fitStruct.header_fichier.NAXIS2; i++)
    {
        for (int j = 0; j < fitStruct.header_fichier.NAXIS1; j++)
        {
            fprintf(fichier_csv, "%hd;", (fitStruct.header_fichier.BZERO + fitStruct.header_fichier.BSCALE * pixels[i * fitStruct.header_fichier.NAXIS1 + j]));
            if (j == fitStruct.header_fichier.NAXIS1 - 1)
            {
                fprintf(fichier_csv, "\n");
            }
        }
    }

    fclose(fichier_csv);
}

/**
 * @brief Convertir une FitStruct en fichier .fit
 *
 * @param fitStruct Structure fitStruct d'une image .fit
 * @param filenameLe Le chemin du fichier .fit dans lequel on va écrire
 */
void ecrire_fit_file(FitStruct fitStruct, char *filename)
{
    FILE *output_file = fopen(filename, "wb");

    // Écrire le header dans le fichier
    fwrite(&fitStruct.header_fichier, sizeof(Header), 1, output_file);

    // Écrire les données dans le fichier
    fwrite(fitStruct.data, sizeof(int16_t), fitStruct.header_fichier.NAXIS1 * fitStruct.header_fichier.NAXIS2, output_file);

    fclose(output_file);
}