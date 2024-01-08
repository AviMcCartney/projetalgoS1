# Projet d'algorithmique - Compte rendu - CATALA Alexandre - DI GIOVANNI Celian - SOUBRY Sophie

## Utilitaire de traitement de photo astronomiques

## Contenu du projet

1. **src** : Ce répertoire contient le code source de l'application.

- `main.c` : Fichier principal contenant le menu intéractif.
- `operation.c` : Fichier contenant les opérations à effectuer sur les fichier .fit.
- ...

2. **include** : Ce répertoire contient les fichiers d'en-tête.

- `fitstruct.h` : Définition de la structure `FitStruct`.
- `header.h` : Définition de la structure `Header`.
- ...

3. **Images** : Ce répertoire contient les images FITS utilisées pour les tests.

4. **Documentation** : Ce répertoire contient la documentation du projet.

5. **build** : Ce répertoire contient les fichiers générés lors de la compilation.

## Compilation et Éxécution

1. Cloner le dépôt
2. Lancer la commande `make clean && make run` dans votre terminal en étant à la racine du projet

## Exemple d'Utilisation

1. Sélectionnez l'option dans le menu interactif.
2. Suivez les instructions pour fournir les fichiers FITS nécessaires.
3. Obtenez les résultats dans votre terminal.

## Gestion du projet

1. Création d'un Git Hub

Pour nous organiser, nous avons mis en place un dépôt Git Hub dans lequel nous avons chacun notre « branche » afin de pouvoir travailler de manière indépendante sur le projet.

Nous pouvions donc suivre les avancements de chacun, et avancer en autonomie.

2. Déroulement du projet

- Compréhension du sujet, des exigences, et du format FITS

- Nous avions dans un premier temps commencé à travailler sur l'exigence **PRIM_30**, qui est de lire et afficher les entêtes de fichier .fit. Une fois la fonction terminée, on a pu passer à la fonction suivante qui permettait d'écrire dans un fichier .csv les valeurs calculées des fichier .fit (exigence **PRIM_40**).

- **BLOQUAGE** : Nous nous sommes rendus compte au cours de notre projet que notre approche n'était pas optimale.  
  En effet, nos fonctions géraient beaucoup de choses en même temps. Par exemple notre fonction qui convertissait les .fit en .csv s'occupaient à la fois :

  - de l'ouverture des fichiers
  - de la gestion de la mémoire
  - de la conversion Little Endian / Big Endian
  - du calcul et de l'écriture des données dans le .csv

- Suite à ces problèmes, nous avons décidés de repartir du début pour repartir sur une base plus adaptés. Nous avons essayé de séparer le plus possible le code en plusieurs fonctions pour éviter les erreurs et les répétitions.

  - Nous avons dû revoir notre façon de manipuler les données FITS, de les stocker en mémoire et de les traiter.
  - Malgré ces difficultés, nous avons réussi à implémenter toutes les fonctionnalités demandées et à respecter les normes de codage.
