#include "fitstruct.h"
#include "lecture.h"
#include "header.h"

struct FitStruct construct_fitstruct(FILE *fichier)
{
    FitStruct fit_fichier;

    Header mon_header = construct_header(fichier);
    fit_fichier.header_fichier = mon_header;
    fit_fichier.data = lire_donnees_image(fichier, mon_header.NAXIS1, mon_header.NAXIS2);

    return fit_fichier;
}
