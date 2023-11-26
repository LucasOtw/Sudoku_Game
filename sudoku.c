/**
 * @file   sudokuv3.c
 * @brief  Programme principal
 * @author Lucas TORRES
 * @date   15 novembre 2023
 * @version 0.1
 */

                        /*****************************************************
                                * AJOUT DES LIBRAIRIES NECESSAIRES*
                        *****************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAILLE 9 // Taille de la grille de sudoku

typedef struct {       // Structure pour la grille
    int grille[TAILLE][TAILLE];
} tGrille;

                        /*****************************************************
                        * FONCTIONS/PROCEDURES POUR LE FONCTIONNEMENT DU JEU*
                        *****************************************************/


void chargerGrille(tGrille *g){
    char nomFichier[30];
    FILE *f;
    printf("Nom du fichier ? ");
    scanf("%s", nomFichier);
    f = fopen(nomFichier, "rb");
    if (f == NULL) {
        printf("\n ERREUR sur le fichier %s\n", nomFichier);
        exit(EXIT_FAILURE);
    } else {
        for (int i = 0; i < TAILLE; i++) {
            for (int j = 0; j < TAILLE; j++) {
                fread(&(g->grille[i][j]), sizeof(int), 1, f);

            }
        }
        fclose(f);
    }
}

void afficherGrille(tGrille g) {
    printf("      ");
    printf("1  2  3   4  5  6   7  8  9\n");
    printf("    +---------+---------+---------+\n");
    for (int ligne = 0; ligne < TAILLE; ligne++) {
        printf("%d   |", ligne + 1);
        for (int colonne = 0; colonne < TAILLE; colonne++) {
            int valeur = g.grille[ligne][colonne];
            if ( valeur == 0 ){
                printf(" . ");
            } else {
                printf(" %d ", valeur);
            }
            if (( colonne + 1) % 3 == 0 && colonne < TAILLE){
                printf("|");
            
            }
            
        }
        printf("\n");
        if ((ligne + 1) % 3 == 0 && ligne < TAILLE){
            printf("    +---------+---------+---------+\n");
         }
    }
}

void saisie(int *valeurF) {
    char valeur[20];
    int valeursouhaitee;
    int conversion = 0;

    do {
        printf("Veuillez entrer une valeur entre 1 et 9 s'il vous plait :\n");
        scanf("%s", valeur);

        if (sscanf(valeur, "%d", &valeursouhaitee) == 1 && valeursouhaitee >= 1 && valeursouhaitee <= 9) {
            *valeurF = valeursouhaitee;
            conversion = 1;  // Pour éviter de multiples return
        } else {
            printf("Veuillez entrer un nombre entier entre 1 et 9 s'il vous plait :\n");
        }
    } while (conversion == 0);
}

bool possible(tGrille g, int ligne, int colonne, int valeur) {
    bool verification = true;   // Pour éviter plusieurs return

                                                                     // Vérification de la colonne
    for (int i = 0; i < TAILLE; i++) {
        if (i != ligne - 1 && g.grille[i][colonne - 1] == valeur) {
            printf("Erreur, la valeur est déjà présente dans la colonne. Veuillez réessayer\n");
            verification = false;
        }
    }

                                                                    // Vérification de la ligne
    for (int j = 0; j < TAILLE; j++) {                    
        if (j != colonne - 1 && g.grille[ligne - 1][j] == valeur) {
            printf("La valeur est déjà présente sur la ligne. Veuillez réessayer :\n");
            verification = false;
        }
    }
    
                                                                    // Vérification des blocs 3x3
    int debutLigne = ligne - (ligne % 3);
    int debutColonne = colonne - (colonne % 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g.grille[i + debutLigne][j + debutColonne] == valeur) {
                printf("La valeur est déjà présente dans le carré 3x3. Veuillez réessayer :\n");
                verification = false;
            }
        }
    }

    return verification;
}



bool estGrilleComplete(tGrille g) {   // Pour verifier que le sudoku est entierement finit
    bool grilleComplete = true;   
    for (int ligne = 0; ligne < TAILLE; ligne++) {
        for (int colonne = 0; colonne < TAILLE; colonne++) {
            if (g.grille[ligne][colonne] == 0) {
                grilleComplete = false;
            }
        }
    }
    return grilleComplete; 
}


                        /*****************************************************
                                        * PROGRAMME PRINCIPAL *
                        *****************************************************/


int main() {
    tGrille g; // Initialise la grille
    int numcolonne, numligne, valeurvoulue; // valeur des colonnes/lignes/valeur
    bool grilleComplete = false; //booleen pour une partie finit
    int souhait;

    do {          // Pour relancer une nouvelle partie si besoin

   
    chargerGrille(&g);
    afficherGrille(g); 
    printf("\033[0;31m"); // Rouge  ( Couleurs optionnel)
    printf("Petit rappel des règles du jeu : \n");
    printf("- Une valeur ne peut être présente qu'une seule fois sur la même ligne / colonne / carré 3x3\n");
    printf("- Veuillez n'entrer que des entiers entre 1 et 9\n");
    printf("\033[0;32m"); // Vert
    printf("Bonne chance !\n");
    printf("\033[0m");  // Retour aux couleurs normales

    while (!grilleComplete) {
        saisie(&numligne);  
        saisie(&numcolonne);
        saisie(&valeurvoulue);

     
    if (possible(g, numligne, numcolonne, valeurvoulue)) {
        g.grille[numligne - 1][numcolonne - 1] = valeurvoulue; // Ajouter la valeur à la grille
        printf("La valeur a bien été ajoutée !\n");

        afficherGrille(g); // pour afficher la grille que l'utilisateur à completer
    
    grilleComplete = estGrilleComplete(g);   // validation de fin quand grille complète
    }
    }
    printf("Félicitation ! Vous avez terminé le sudoku !");
    printf("Voulez-vous recommencer une nouvelle partie ? ( 1 : Oui, 2 : Non :)\n");
    scanf("%d", &souhait);                                     // corriger cette partie du code
    if ( souhait == 1 ) {
        printf("Lancement de la nouvelle partie...\n");  // texte optionnel pour signaler le chargement d'une nouvelle grille pour l'utilisateur

    }else {
        printf("Fin de partie. Bonne journée");
        
    
    }
    } while ( souhait == 1);  // condition pour recommencer une nouvelle partie ou non
     
    
    return EXIT_SUCCESS;

}   //fin du programme
