// Commentaire main.c
// CDataframe
// Justine GARNUNG et Yéléna SAINTE-ROSE BRUNY
// Rôle : Programme principal qui permet de tester toutes les fonctions de la librairie.

#include <stdio.h>
#include <string.h>
#include "cdataframe.h"
#include "column.h"
#include <ctype.h>
#include "menu.h"

// Fonction principale qui permet de tester les fonctions de la librairie.
// Elle ne prend pas de paramètres et retourne 0.
int main() {
    printf("Voulez-vous tester les fonctions ?\n");
    char choice[4];
    scanf("%s", choice);
    for(int i = 0; choice[i]; i++) {
        choice[i] = tolower(choice[i]);
    }
    if (strcmp(choice, "oui") == 0){
        CDataframe df;
        create_cdataframe(&df);
        interactive_menu(&df);
    }
    else {
        printf("D'accord, aurevoir ! (Vous pouvez relancer le programme.)\n");
    }
    return 0;
}