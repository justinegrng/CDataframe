// Commentaire menu.c
// CDataframe
// Justine GARNUNG et Yéléna SAINTE-ROSE BRUNY
// Rôle : Implémentation des fonctions du menu interactif.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "cdataframe.h"
#include "column.h"

// Fonction qui affiche le menu interactif
// Elle ne prend pas de paramètres et ne retourne rien.
void print_menu(){
    printf("1. Creer votre dataframe\n");
    printf("2. Ajouter une colonne\n");
    printf("3. Supprimer une colonne\n");
    printf("4. Renommer une colonne\n");
    printf("5. Trouver une valeur\n");
    printf("6. Trouver la valeur d'une cellule\n");
    printf("7. Mettre la valeur dans une cellule\n");
    printf("8. Afficher le nom des colonnes\n");
    printf("9. Compter les lignes\n");
    printf("10. Compter les colonnes\n");
    printf("11. Nombre de cellules contenant une valeur egale\n");
    printf("12. Nombre de cellules contenant une valeur superieure\n");
    printf("13. Nombre de cellules contenant une valeur inferieure\n");
    printf("14. Afficher les 5 premieres lignes\n");
    printf("15. Afficher les 2 premieres colonnes\n");
    printf("16. Ajouter une ligne\n");
    printf("17. Supprimer une ligne\n");
    printf("18. Quitter\n");
}

// Fonction qui permet de choisir entre un dataframe vide, un dataframe avec des valeurs en dur ou de saisir les valeurs
// Elle ne prend pas de paramètres et retourne un entier.
void interactive_menu (CDataframe* df) {
    int choice;
    print_menu();
    int result = scanf("%d", &choice);

    if (result != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    char column_name[50];
    int index;
    char value[50];
    int row, col;

    switch(choice) {
        case 1:
            printf("Veux tu un dataframe vide ou un dataframe avec des valeurs en dur ou saisir toi-même les valeurs ?\n");
            printf("1. Dataframe vide\n");
            printf("2. Dataframe avec des valeurs en dur\n");
            printf("3. Saisir les valeurs\n");
            menu_choice_1();
            return;

        case 2:
            printf("Entrer le nom de la colonne: \n");
            scanf("%s", column_name);
            Column column;
            create_column(&column, column_name, 0);
            add_column(df, &column);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 3:
            printf("Entrer l index de la colonne a supprimer: \n");
            scanf("%d", &index);
            delete_column_at_index(df, index);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 4:
            printf("Entrer l index de la colonne a renommer: \n");
            scanf("%d", &index);
            printf("Enter new name: ");
            scanf("%s", column_name);
            rename_column(df, index, column_name);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 5:
            printf("Entrer une valeur a chercher: \n");
            scanf("%s", value);
            find_value(df, value);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 6:
            printf("Entrer l index de la ligne et de la colonne: \n");
            scanf("%d %d", &row, &col);
            get_cell_value(df, row, col);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 7:
            printf("Entrer l index de la ligne et de la colonne: \n");
            scanf("%d %d", &row, &col);
            printf("Enter new value: \n");
            scanf("%s", value);
            set_cell_value(df, row, col, value);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 8:
            print_column_names(df);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 9:
            int nb_rows = count_rows(df);
            printf("Nombre de lignes: %d\n", nb_rows);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 10:
            int nb_columns = count_columns(df);
            printf("Nombre de colonnes: %d\n", nb_columns);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 11:
            printf("Entrer une valeur a compter: \n");
            int value;
            scanf("%d", &value);
            int count_eq = count_cells_equal(df, &value);
            printf("Nombre de cellules egales a %d: %d\n", value, count_eq);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 12:
            printf("Entrer une valeur a comparer: \n");
            scanf("%s", value);
            int count_gt = count_cells_greater(df, value);
            printf("Nombre de cellules superieures %s: %d\n", value, count_gt);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 13:
            printf("Entrer une valeur a comparer: \n");
            scanf("%s", value);
            int count_lt = count_cells_less(df, value);
            printf("Nombre de cellules inferieures a %s: %d\n", value, count_lt);
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 14:
            print_dataframe_limited_rows(df, 5);
            interactive_menu(df);
            return;
        case 15:
            print_dataframe_limited_columns(df, 2);
            interactive_menu(df);
            return;
        case 16:
            add_row(df, (void**) "test");
            print_dataframe(df);
            interactive_menu(df);
            return;
        case 17:
            delete_row_print(df, 1);
            interactive_menu(df);
            return;
        case 18:
            printf("Au revoir !\n");
            return;
        default:
            printf("Choix non valide. Veuillez réessayer.\n");
            interactive_menu(df);
            return;
    }
}

// Fonction qui permet de choisir entre un dataframe vide, un dataframe avec des valeurs en dur ou de saisir les valeurs
// Elle ne prend pas de paramètres et retourne un entier.
int menu_choice_1 (){
    int choice1;
    scanf("%d", &choice1);
    if (choice1==1){
        CDataframe df;
        create_cdataframe(&df);
        print_dataframe(&df);
        interactive_menu(&df);
    } else if (choice1==2){
        CDataframe df;
        create_cdataframe(&df);
        Column column1;
        create_column(&column1, "Colonne 1", 0);
        Column column2;
        create_column(&column2, "Colonne 2", 1);
        Column column3;
        create_column(&column3, "Colonne 3", 2);
        add_column(&df, &column1);
        add_column(&df, &column2);
        add_column(&df, &column3);
        int value1 = 1;
        insert_value(&column1, &value1);
        int value2 = 2;
        insert_value(&column1, &value2);
        char value3[50] = "bonjour";
        insert_value(&column2, value3);
        double value4 = 3.14;
        insert_value(&column3, &value4);
        print_dataframe(&df);
        interactive_menu(&df);
    } else if (choice1==3){
        CDataframe df;
        create_cdataframe(&df);
        fill_dataframe_user(&df);
        print_dataframe(&df);
        interactive_menu(&df);
    }

};

