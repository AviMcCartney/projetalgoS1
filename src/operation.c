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

FitStruct somme_image(FitStruct images, int nombre_images) {}