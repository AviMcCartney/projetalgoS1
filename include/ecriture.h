#ifndef ECRITURE_H
#define ECRITURE_H
#include "fitstruct.h"
#include "lecture.h"

void ecrire_pixels_csv(FitStruct fitStruct, char *nom_fichier_csv);
void ecrire_fit_file(FitStruct fitStruct, char *filename);

#endif // ECRITURE_H