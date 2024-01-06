/**
 * @file fitstruct.c
 * @author Alexandre, Célian, Sophie
 * @brief Fichier fitstruct.c contenant l'ensemble des fonctions pour traiter les fitstruct
 * @version 0.1
 * @date 2024-01-06
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "fitstruct.h"
#include "lecture.h"
#include "header.h"

/**
 * @brief On passe un fichier en paramètre et on construit sa structure FitStruct. Dans cette structure on stockera les données de l'image et son header. Cette structure nous permettra de faire les opérations sur les images et l'écriture du CSV.
 *
 * @param fichier Le chemin du fichier .fit pour lequel on veut obtenir sa structure FitStruct.
 * @return struct FitStruct
 */
struct FitStruct construct_fitstruct(FILE *fichier)
{
    FitStruct fit_fichier;

    Header mon_header = construct_header(fichier);
    fit_fichier.header_fichier = mon_header;
    fit_fichier.data = lire_donnees_image(fichier, mon_header.NAXIS1, mon_header.NAXIS2);

    return fit_fichier;
}
