/**
 * @file main.c
 * @author Alexandre, Célian, Sophie
 * @brief fichier main.c contenant les procédures de test
 * @version 0.1
 * @date 2023-12-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "prototype.h"

int main(int argc, char const *argv[])
{

    // Affiche le header de l'image .fit passé en paramètre.
    //  read_sortie("../Images/darks/darks_00012.fit");

    // Converti l'image passé en paramètre en CSV
    // conversion_csv("../Images/lights/r_lights_00001.fit", "test.csv");

    somme_image("../Images/lights/r_lights_00001.fit", "../Images/lights/r_lights_00002.fit", "test.fit");

    return 0;
}
