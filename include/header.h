/**
 * @file header.h
 * @author Alexandre, Célian, Sophie
 * @brief Fichier header.h contenant l'ensemble des prototypes et des déclarations pour les header
 * @version 0.1
 * @date 2023-12-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#ifndef HEADER_H
#define HEADER_H
#define NB_LIGNES_HEADER 36
#define LONGUEUR_LIGNES_HEADER 80
#define OCTETS_HEADER 2880
#define NB_CLES_VALIDES 7

/**
 * @brief Structure du Header d'un fichier .fit. Cette structure nous permettra de stocker les informations importantes d'un header.
 *
 */
typedef struct Header
{
    char SIMPLE;
    int BITPIX;
    int NAXIS;
    int NAXIS1;
    int NAXIS2;
    int NAXIS3;
    int BZERO;
    int BSCALE;
} Header;

int cle_valide(char *cle);
void afficher_header(char header[OCTETS_HEADER]);
void process_header(Header *mon_header, char packet80[LONGUEUR_LIGNES_HEADER]);
struct Header construct_header(FILE *mon_fichier);

#endif // HEADER_H