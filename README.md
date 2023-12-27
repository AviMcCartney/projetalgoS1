# Projet d'algorithmique - CATALA Alexandre - DI GIOVANNI Celian - SOUBRY Sophie

## Projet d'algorithmique - Utilitaire de traitement de photo astronomiques

1. Cloner le dépôt (ou si c'est déjà fait mettre à jour votre branche)
2. Lancer la commande `make clean && make run` dans votre terminal en étant à la racine du projet

### La différence avec ce qu'on faisait avant

Le problème dans notre ancien code, c'était que dans une seule fonction, on faisait tout en même temps :

- Ouvrir un fichier
- Faire les malloc
- Lire les données
- Faire la conversion Big / Little endian
- Écrire les données
- ...

Pas hyper opti quoi, du coup maintenant le but c'est de séparer en plusieurs fichier tous nos besoins.

Si on veut écrire des données, on fera la fonction dans ecriture.c, si on veut ecrire des données comme dans le csv on fera une fonction dans ecriture.c. Chaque .c à son .h avec les prototypes qu'il faut.

Pour faire les opérations, on fera un nouveau .c comme operations.c dans le dossier /src avec les fonctions et on n'oubliera pas de faire son .h dans /include par la suite. Si dans ce fichier on a besoin d'autre fonctions comme par exemple celle qui permet de construire une FitStruct on aura juste à `#include "fitstruct.h` en début de fichier. On include **que** les .h jamais les .c.
