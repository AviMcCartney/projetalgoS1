/**
 * @file header.c
 * @author Alexandre, Célian, Sophie
 * @brief Fichier header.c contenant l'ensemble des fonctions pour traiter les header
 * @version 0.1
 * @date 2023-12-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "lecture.h"
#include "header.h"

/**
 * @brief Affiche le header passé en paramètre
 *
 * @param header
 */
void afficher_header(char header[OCTETS_HEADER])
{
    for (int i = 0; i < NB_LIGNES_HEADER * LONGUEUR_LIGNES_HEADER; i++)
    {
        printf("%c%s", header[i], (i + 1) % LONGUEUR_LIGNES_HEADER ? "" : "\n");
    }
}

/**
 * @brief Renvoie 1 si la clé passé en paramètre est contenue dans la liste, 0 sinon.
 *
 * @param cle
 * @return int
 */
int cle_valide(char *cle)
{
    int estValide = 0;

    char *cles_valides[NB_CLES_VALIDES] = {"BITPIX", "NAXIS", "NAXIS1", "NAXIS2", "NAXIS3", "BZERO", "BSCALE"};

    for (int i = 0; i < NB_CLES_VALIDES; i++)
    {
        if (strcmp(cle, cles_valides[i]) == 0)
        {
            estValide = 1;
        }
    }
    return estValide;
}

/**
 * @brief Associe les valeurs contenues dans le header aux variables de la structure pour pouvoir les conserver et les utiliser ultérieurement.
 *
 * @param mon_header
 * @param packet80
 */
void process_header(Header *mon_header, char packet80[LONGUEUR_LIGNES_HEADER])
{
    char cle[8];
    char valeur[72];
    if (sscanf(packet80, "%7s = %71[^\n]", cle, valeur) == 2)
    {
        // printf("CLE: %s\n", cle);
        // printf("VALEUR: %s\n", valeur);
        // if (!cle_valide(cle))
        //     return;
        if (!strncmp(cle, "NAXIS", 6))
        {
            mon_header->NAXIS = atoi(valeur);
            return;
        }
        if (!strncmp(cle, "NAXIS1", 6))
        {
            mon_header->NAXIS1 = atoi(valeur);
            return;
        }
        if (!strncmp(cle, "NAXIS2", 6))
        {
            mon_header->NAXIS2 = atoi(valeur);
            return;
        }
        if (!strncmp(cle, "NAXIS3", 6))
        {
            mon_header->NAXIS3 = atoi(valeur);
            return;
        }
        if (!strncmp(cle, "BZERO", 5))
        {
            mon_header->BZERO = atoi(valeur);
            return;
        }
        if (!strncmp(cle, "BSCALE", 6))
        {
            mon_header->BSCALE = atoi(valeur);
            return;
        }
        if (!strncmp(cle, "BITPIX", 6))
        {
            mon_header->BITPIX = atoi(valeur);
            return;
        }
    }
}

/**
 * @brief Construit la structure du Header associée au fichier passé en paramètre.
 *
 * @param mon_fichier
 * @return struct Header
 */
struct Header construct_header(FILE *mon_fichier)
{
    char *data = lire_donnees_header(mon_fichier);
    Header mon_header = {0};

    for (int i = 0; i < NB_LIGNES_HEADER; i++)
    {
        char ligne[LONGUEUR_LIGNES_HEADER + 1];
        strncpy(ligne, &data[i * LONGUEUR_LIGNES_HEADER], LONGUEUR_LIGNES_HEADER);
        ligne[LONGUEUR_LIGNES_HEADER] = '\0';

        process_header(&mon_header, ligne);
    }

    printf("\n*****************************************");
    printf("\nLes données importantes du header à retenir sont :");
    printf("\nBITPIX = %d, NAXIS = %d, NAXIS1 = %d, NAXIS2= %d, NAXIS3= %d, BZERO = %d, BSCALE = %d\n", mon_header.BITPIX, mon_header.NAXIS, mon_header.NAXIS1, mon_header.NAXIS2, mon_header.NAXIS3, mon_header.BZERO, mon_header.BSCALE);

    free(data);
    return mon_header;
}