/**
 * @file prototype.h
 * @author Alexandre, Célian, Sophie
 * @brief Fichiers contenant les prototypes de nos fonctions
 * @version 0.1
 * @date 2023-12-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct header read_sortie(char *chemin_fichier);
struct header conversion_csv(char *chemin_fichier, char *chemin_fichier_csv);
void somme_image(const char *chemin_fichier1, const char *chemin_fichier2, const char *chemin_fichier_sortie);

struct header
{
    char SIMPLE;
    int BITPIX;
    int NAXIS;
    int NAXIS1;
    int NAXIS2;
    int NAXIS3;
    char EXTEND[69];
    int BZERO;
    int BSCALE;
    char INSTRUME[69];
    char DATE[69];
    float XPIXSZ;
    float YPIXSZ;
    int XBINNING;
    int YBINNING;
    float EXPTIME;
    char BAYERPAT[69];
    int XBAYROFF;
    int YBAYROFF;
    char PROGRAM[69];
    int **DATA;
};
