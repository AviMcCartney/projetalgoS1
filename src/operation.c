#include "operation.h"
#include "fitstruct.h"
#include <limits.h>

/**
 * @brief Retourne 1 si les header sont compatibles, 0 sinon
 *
 * @param images
 * @param nombre_images
 * @return int
 */
int headers_compatible(FitStruct *images, int nombre_images)
{
    for (int i = 1; i < nombre_images; i++)
    {
        if (images[0].header_fichier.NAXIS1 != images[i].header_fichier.NAXIS1 ||
            images[0].header_fichier.NAXIS2 != images[i].header_fichier.NAXIS2 ||
            images[0].header_fichier.BITPIX != images[i].header_fichier.BITPIX)
        {
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Renvoie la somme des images en fonction d'une liste d'image passés en paramètre
 *
 * @param images
 * @param nombre_images
 * @return FitStruct
 */
FitStruct somme_image(FitStruct *images, int nombre_images)
{
    // Vérifier la compatibilité des headers
    if (!headers_compatible(images, nombre_images))
    {
        fprintf(stderr, "Les headers des images ne sont pas compatibles.\n");
    }
    FitStruct resultat;
    int naxis1 = images[0].header_fichier.NAXIS1;
    int naxis2 = images[0].header_fichier.NAXIS2;

    // Initialiser la structure résultat et allouer la mémoire pour les données
    resultat.header_fichier = images[0].header_fichier; // Copier le header de la première image
    resultat.data = (int16_t *)malloc(naxis1 * naxis2 * sizeof(int16_t));

    // Initialiser les données à 0
    memset(resultat.data, 0, naxis1 * naxis2 * sizeof(uint16_t));

    // Sommation des images
    for (int i = 0; i < naxis2; i++)
    {
        for (int j = 0; j < naxis1; j++)
        {
            int32_t somme = 0;
            for (int k = 0; k < nombre_images; k++)
            {
                somme += images[k].data[i * naxis1 + j];
            }
            resultat.data[i * naxis1 + j] = (somme > INT16_MAX) ? INT16_MAX : ((somme < INT16_MIN) ? INT16_MIN : somme);
        }
    }

    return resultat;
}

/**
 * @brief Affiche le nombre de valeurs d'une FitStruct, permet de vérifier les calculs des opérations
 *
 * @param image
 * @param nombre_valeurs
 */
void afficher_premieres_valeurs(FitStruct image, int nombre_valeurs)
{
    for (int i = 0; i < nombre_valeurs; i++)
    {
        printf("Valeur brute %d: %hd\n", i, image.data[i]);
    }
}

/**
 * @brief Renvoie la moyenne des images en fonction d'une liste d'image passés en paramètre
 *
 * @param images
 * @param nombre_images
 * @return FitStruct
 */
FitStruct moyenne_image(FitStruct *images, int nombre_images)
{
    // Vérifier la compatibilité des headers
    if (!headers_compatible(images, nombre_images))
    {
        fprintf(stderr, "Les headers des images ne sont pas compatibles.\n");
    }
    FitStruct resultat;
    int naxis1 = images[0].header_fichier.NAXIS1;
    int naxis2 = images[0].header_fichier.NAXIS2;

    // Initialiser la structure résultat et allouer la mémoire pour les données
    resultat.header_fichier = images[0].header_fichier; // Copier le header de la première image
    resultat.data = (int16_t *)malloc(naxis1 * naxis2 * sizeof(int16_t));

    // Initialiser les données à 0
    memset(resultat.data, 0, naxis1 * naxis2 * sizeof(uint16_t));

    // Moyenne des images
    for (int i = 0; i < naxis2; i++)
    {
        for (int j = 0; j < naxis1; j++)
        {
            double moyenne = 0.0;
            for (int k = 0; k < nombre_images; k++)
            {
                moyenne += images[k].data[i * naxis1 + j];
            }
            moyenne /= nombre_images; // Calcul de la moyenne
            resultat.data[i * naxis1 + j] = (moyenne > INT16_MAX) ? INT16_MAX : (moyenne < INT16_MIN) ? INT16_MIN
                                                                                                      : (int16_t)moyenne; // Gérer les débordements : on vérifie si la moyenne ne dépasse pas les valeurs min ou max
        }
    }

    return resultat;
}

/**
 * @brief Renvoie la division de 2 images passés en paramètre
 *
 * @param images1
 * @param images2
 * @return FitStruct
 */
FitStruct diviser_image(FitStruct images1, FitStruct images2)
{
    // Vérifier la compatibilité des headers
    if (!headers_compatible(&images1, 1) || !headers_compatible(&images2, 1))
    {
        fprintf(stderr, "Les headers des images ne sont pas compatibles.\n");
    }

    FitStruct resultat;
    int naxis1 = images1.header_fichier.NAXIS1;
    int naxis2 = images1.header_fichier.NAXIS2;

    // Initialiser la structure résultat et allouer la mémoire pour les données
    resultat.header_fichier = images1.header_fichier;
    resultat.data = (int16_t *)malloc(naxis1 * naxis2 * sizeof(int16_t));

    // Division des images
    for (int i = 0; i < naxis2; i++)
    {
        for (int j = 0; j < naxis1; j++)
        {
            int32_t numerateur = images1.data[i * naxis1 + j];
            int32_t denominateur = images2.data[i * naxis1 + j];

            if (denominateur != 0)
            {
                double resultat_division = (double)numerateur / denominateur;
                resultat.data[i * naxis1 + j] = (resultat_division > INT16_MAX) ? INT16_MAX : (resultat_division < INT16_MIN) ? INT16_MIN
                                                                                                                              : (int16_t)resultat_division;
            }
            else
            {
                // si on divise par 0, la valeur par défaut sera 0
                resultat.data[i * naxis1 + j] = 0;
            }
        }
    }

    return resultat;
}

/**
 * @brief Renvoie la différence de 2 images passés en paramètre
 *
 * @param images1
 * @param images2
 * @return FitStruct
 */
FitStruct soustraire_image(FitStruct images1, FitStruct images2)
{
    // Vérifier la compatibilité des headers
    if (!headers_compatible(&images1, 1) || !headers_compatible(&images2, 1))
    {
        fprintf(stderr, "Les headers des images ne sont pas compatibles.\n");
    }

    FitStruct resultat;
    int naxis1 = images1.header_fichier.NAXIS1;
    int naxis2 = images1.header_fichier.NAXIS2;

    // Initialiser la structure résultat et allouer la mémoire pour les données
    resultat.header_fichier = images1.header_fichier;
    resultat.data = (int16_t *)malloc(naxis1 * naxis2 * sizeof(int16_t));

    // Soustraction des images
    for (int i = 0; i < naxis2; i++)
    {
        for (int j = 0; j < naxis1; j++)
        {
            int32_t difference = images1.data[i * naxis1 + j] - images2.data[i * naxis1 + j];
            resultat.data[i * naxis1 + j] = (difference < INT16_MIN) ? INT16_MIN : (difference > INT16_MAX) ? INT16_MAX
                                                                                                            : (int16_t)difference;
        }
    }

    return resultat;
}