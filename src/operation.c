#include "operation.h"
#include "fitstruct.h"

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

// FitStruct somme_image(FitStruct *images, int nombre_images)
// {
//     // Vérifier la compatibilité des headers
//     if (!headers_compatible(images, nombre_images))
//     {
//         fprintf(stderr, "Les headers des images ne sont pas compatibles.\n");
//     }
//     FitStruct resultat;
//     int naxis1 = images[0].header_fichier.NAXIS1;
//     int naxis2 = images[0].header_fichier.NAXIS2;

//     // Initialiser la structure résultat et allouer la mémoire pour les données
//     resultat.header_fichier = images[0].header_fichier; // Copier le header de la première image
//     resultat.data = (uint16_t *)malloc(naxis1 * naxis2 * sizeof(uint16_t));

//     // Initialiser les données à 0
//     memset(resultat.data, 0, naxis1 * naxis2 * sizeof(uint16_t));

//     // Sommation des images
//     for (int i = 0; i < naxis2; i++)
//     {
//         for (int j = 0; j < naxis1; j++)
//         {
//             uint32_t somme = 0;
//             for (int k = 0; k < nombre_images; k++)
//             {
//                 somme += images[k].data[i * naxis1 + j];
//             }
//             resultat.data[i * naxis1 + j] = (somme > UINT16_MAX) ? UINT16_MAX : somme; // Gérer les débordements
//         }
//     }

//     return resultat;
// }
