# Documentation du Jeu de Sudoku en C

## Introduction

Ce projet est un jeu de Sudoku développé en langage C. Le jeu permet aux joueurs de choisir parmi différentes grilles de Sudoku et de placer des chiffres pour compléter la grille. Le jeu vérifie les entrées pour s'assurer qu'elles respectent les règles du Sudoku.

## Fonctionnalités

- **Choix de la grille** : Le joueur peut choisir parmi plusieurs grilles prédéfinies.
- **Placement des chiffres** : Le joueur peut choisir où placer les chiffres dans la grille.
- **Vérification de la validité** : Le jeu vérifie si le placement du chiffre est valide selon les règles du Sudoku.
- **Interface utilisateur** : Le jeu propose une interface utilisateur simple pour une expérience de jeu fluide.

## Installation

Pour compiler et exécuter le jeu, vous devez disposer d'un compilateur C, tel que `gcc`. Suivez les étapes ci-dessous pour installer et exécuter le jeu.

### Étapes

1. Clonez le dépôt ou téléchargez les fichiers source du jeu.
2. Ouvrez un terminal et naviguez jusqu'au répertoire contenant les fichiers source.
3. Compilez le programme en utilisant la commande suivante :
    ```sh
    gcc -o sudoku sudoku.c
    ```
4. Exécutez le programme avec la commande :
    ```sh
    ./sudoku
    ```

## Utilisation

### Menu Principal

Lors de l'exécution du jeu, le joueur sera présenté avec un menu principal où il pourra choisir parmi plusieurs options :

1. **Choisir une grille** : Permet de sélectionner une grille de Sudoku à partir d'une liste de grilles prédéfinies.
2. **Placer un chiffre** : Permet de placer un chiffre à une position spécifique sur la grille.
3. **Quitter le jeu** : Permet de quitter le jeu.

### Choix de la Grille

Le joueur peut choisir une grille de Sudoku en entrant le numéro correspondant à la grille souhaitée.

### Placement des Chiffres

Le joueur peut entrer les coordonnées (ligne et colonne) et le chiffre à placer. Le jeu vérifiera si le placement est valide avant de mettre à jour la grille.

### Exemple de Session de Jeu

```plaintext
Bienvenue dans le jeu de Sudoku!

1. Choisir une grille
2. Placer un chiffre
3. Quitter le jeu

Choisissez une option: 1

Grilles disponibles:
1. Grille 1
2. Grille 2
3. Grille 3

Choisissez une grille (1-3): 1

Vous avez choisi la Grille 1.

Grille actuelle:
5 3 0 | 0 7 0 | 0 0 0
6 0 0 | 1 9 5 | 0 0 0
0 9 8 | 0 0 0 | 0 6 0
---------------------
8 0 0 | 0 6 0 | 0 0 3
4 0 0 | 8 0 3 | 0 0 1
7 0 0 | 0 2 0 | 0 0 6
---------------------
0 6 0 | 0 0 0 | 2 8 0
0 0 0 | 4 1 9 | 0 0 5
0 0 0 | 0 8 0 | 0 7 9

Entrez la ligne (1-9): 1
Entrez la colonne (1-9): 3
Entrez le chiffre (1-9): 4

Grille mise à jour:
5 3 4 | 0 7 0 | 0 0 0
6 0 0 | 1 9 5 | 0 0 0
0 9 8 | 0 0 0 | 0 6 0
---------------------
8 0 0 | 0 6 0 | 0 0 3
4 0 0 | 8 0 3 | 0 0 1
7 0 0 | 0 2 0 | 0 0 6
---------------------
0 6 0 | 0 0 0 | 2 8 0
0 0 0 | 4 1 9 | 0 0 5
0 0 0 | 0 8 0 | 0 7 9

1. Choisir une grille
2. Placer un chiffre
3. Quitter le jeu

Choisissez une option:
