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
#include <stdio.h>

void read_sortie(const char *chemin_fichier);

struct header
{
    char SIMPLE;
    int BITPIX;
    int NAXIS;
    int NAXIS1;
    int NAXIS2;
    int NAXIS3;
    char EXTEND[69];
    float BZERO;
    float BSCALE;
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
};
