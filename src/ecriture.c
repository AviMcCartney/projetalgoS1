#include "ecriture.h"
#include "header.h"
#include "lecture.h"

/**
 * @brief Écrit les valeurs réelles d'une image dans un fichier CSV valeur_réelle = BZERO + BSCALE × valeur_enregistrée
 *
 * @param fitStruct
 * @param nom_fichier_csv
 */
void ecrire_pixels_csv(FitStruct fitStruct, char *nom_fichier_csv)
{
    FILE *fichier_csv = ouvrir_fichier(nom_fichier_csv, "w");

    uint16_t *pixels = fitStruct.data;
    for (int i = 0; i < fitStruct.header_fichier.NAXIS2; i++)
    {
        for (int j = 0; j < fitStruct.header_fichier.NAXIS1; j++)
        {
            fprintf(fichier_csv, "%hd;", (fitStruct.header_fichier.BSCALE * fitStruct.header_fichier.BZERO + pixels[i * fitStruct.header_fichier.NAXIS1 + j]));
            if (j == fitStruct.header_fichier.NAXIS1 - 1)
            {
                fprintf(fichier_csv, "\n");
            }
        }
    }

    fclose(fichier_csv);
}