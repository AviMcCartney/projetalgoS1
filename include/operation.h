#ifndef OPERATION_H
#define OPERATION_H
#include "fitstruct.h"

int headers_compatible(FitStruct *images, int nombre_images);
FitStruct somme_image(FitStruct images, int nombre_images);

#endif // OPERATION_H