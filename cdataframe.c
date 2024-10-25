// Commentaire cdataframe.c
// CDataframe
// Justine GARNUNG et Yéléna SAINTE-ROSE BRUNY
// Rôle : Implémentation des fonctions de la structure CDataframe.

// Utilisation d'un tableau de colonnes pour stocker les données et non d'une liste doublement chaînée.
// Voir fonction add_column pour plus de détails.
// Avec dataframe->columns qui est un tableau de pointeurs vers des objets Column.
// L'utilisation de la fonction realloc pour redimensionner le tableau de colonnes dans le CDataframe.
// PS : Toutes les fonctions ne sont pas toutes corrigées et utilisables.

#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

// Fonction qui crée un dataframe
// Ses paramètres sont un pointeur sur le dataframe à créer.
// Elle ne retourne rien.
void create_cdataframe(CDataframe* dataframe) {
    dataframe->columns = NULL;
    dataframe->size = 0;
}

// Fonction qui ajoute une colonne à un dataframe
// Ses paramètres sont un pointeur sur le dataframe et un pointeur sur la colonne à ajouter.
// Elle ne retourne rien.
void add_column(CDataframe* dataframe, Column* column) {
    dataframe->columns = realloc(dataframe->columns, (dataframe->size + 1) * sizeof(Column*));
    dataframe->columns[dataframe->size] = column;
    dataframe->size++;
}

// Fonction qui supprime une colonne à un dataframe
// Ses paramètres sont un pointeur sur le dataframe et l'index de la colonne à supprimer.
// Elle ne retourne rien.
void delete_column_at_index(CDataframe* dataframe, int index) {
    if (index < 0 || index >= dataframe->size) {
        return;
    }
    delete_column(&(dataframe->columns[index]));
    for (int i = index; i < dataframe->size - 1; i++) {
        dataframe->columns[i] = dataframe->columns[i + 1];
    }
    dataframe->columns = realloc(dataframe->columns, (dataframe->size - 1) * sizeof(Column*));
    dataframe->size--;
}

// Fonction qui renomme une colonne
// Ses paramètres sont un pointeur sur le dataframe, l'index de la colonne à renommer et le nouveau nom.
// Elle ne retourne rien.
void rename_column(CDataframe* dataframe, int index, char* new_name) {
    if (index < 0 || index >= dataframe->size) {
        return;
    }
    free(dataframe->columns[index]->name);
    dataframe->columns[index]->name = strdup(new_name);
}

// Fonction qui trouve une valeur dans un dataframe
// Ses paramètres sont un pointeur sur le dataframe et la valeur à chercher.
// Elle retourne 1 si la valeur est trouvée et 0 sinon.
int find_value(CDataframe* dataframe, void* value) {
    for (int i = 0; i < dataframe->size; i++) {
        if (count_value(dataframe->columns[i], value) > 0) {
            return 1;
        }
    }
    return 0;
}

// Fonction qui retourne la valeur d'une cellule
// Ses paramètres sont un pointeur sur le dataframe, l'index de la ligne et l'index de la colonne.
// Elle retourne la valeur de la cellule.
void* get_cell_value(CDataframe* dataframe, int row, int col) {
    if (col < 0 || col >= dataframe->size) {
        return NULL;
    }
    return get_value(dataframe->columns[col], row);
}

// Fonction qui modifie la valeur d'une cellule
// Ses paramètres sont un pointeur sur le dataframe, l'index de la ligne, l'index de la colonne et la nouvelle valeur.
// Elle ne retourne rien.
void set_cell_value(CDataframe* dataframe, int row, int col, void* value) {
    if (col < 0 || col >= dataframe->size) {
        return;
    }
    update_value(dataframe->columns[col], row, value);
}

// Fonction qui affiche les noms des colonnes
// Ses paramètres sont un pointeur sur le dataframe.
// Elle ne retourne rien.
void print_column_names(CDataframe* dataframe) {
    for (int i = 0; i < dataframe->size; i++) {
        printf("%s ", dataframe->columns[i]->name);
    }
    printf("\n");
}

// Fonction qui compte le nombre de lignes
// Ses paramètres sont un pointeur sur le dataframe.
// Elle retourne le nombre de lignes.
int count_rows(CDataframe* dataframe) {
    int max_rows = 0;
    for (int i = 0; i < dataframe->size; i++) {
        if (dataframe->columns[i]->size > max_rows) {
            max_rows = dataframe->columns[i]->size;
        }
    }
    return max_rows;
}

// Fonction qui compte le nombre de colonnes
// Ses paramètres sont un pointeur sur le dataframe.
// Elle retourne le nombre de colonnes.
int count_columns(CDataframe* dataframe) {
    return dataframe->size;
}

// Fonction qui compte le nombre de cellules égales à une valeur
// Ses paramètres sont un pointeur sur le dataframe et la valeur à chercher.
// Elle retourne le nombre de cellules égales à la valeur.
int count_cells_equal(CDataframe* dataframe, void* value) {
    int count = 0;
    for (int i = 0; i < dataframe->size; i++) {
        count += count_value(dataframe->columns[i], value);
    }
    return count;
}

// Fonction qui compte le nombre de cellules supérieures à une valeur
// Ses paramètres sont un pointeur sur le dataframe et la valeur à chercher.
// Elle retourne le nombre de cellules supérieures à la valeur.
int count_cells_greater(CDataframe* dataframe, void* value) {
    int count = 0;
    for (int i = 0; i < dataframe->size; i++) {
        count += count_greater_than(dataframe->columns[i], value);
    }
    return count;
}

// Fonction qui compte le nombre de cellules inférieures à une valeur
// Ses paramètres sont un pointeur sur le dataframe et la valeur à chercher.
// Elle retourne le nombre de cellules inférieures à la valeur.
int count_cells_less(CDataframe* dataframe, void* value) {
    int count = 0;
    for (int i = 0; i < dataframe->size; i++) {
        count += count_less_than(dataframe->columns[i], value);
    }
    return count;
}

// Fonction qui affiche un dataframe
// Ses paramètres sont un pointeur sur le dataframe.
// Elle ne retourne rien.
void print_dataframe(CDataframe* df) {
    if (df->size == 0) {
        printf("Le dataframe est vide.\n");
        return;
    }
    for (int i = 0; i < df->size; i++) {
        printf("%s\t", df->columns[i]->name);
    }
    printf("\n");

    int rows = count_rows(df);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < df->size; j++) {
            void* value = get_cell_value(df, i, j);
            if (value != NULL) {
                switch (df->columns[j]->type) {
                    case INT:
                        printf("%d\t", *(int*)value);
                        break;
                    case FLOAT:
                        printf("%.4f\t", *(float*)value);
                        break;
                    case STRING:
                        printf("%s\t", (char*)value);
                        break;
                }
            } else {
                printf("NULL\t");
            }
        }
        printf("\n");
    }
}

// Fonction qui crée un dataframe avec des valeurs de l'utilisateur
// Elle ne prend pas de paramètres et ne retourne rien.
void fill_dataframe_user (CDataframe *dataframe){
    int nb_columns;
    printf("Enter the number of columns:\n");
    scanf("%d", &nb_columns);
    for (int i = 0; i < nb_columns; i++){
        Column* column = malloc(sizeof(Column));
        char name[100];
        printf("Enter the name of the column:\n");
        scanf("%s", name);
        create_column(column, name, 0);
        add_column(dataframe, column);
    }
    int nb_rows;
    printf("Enter the number of rows:\n");
    scanf("%d", &nb_rows);
    for (int i = 0; i < nb_rows; i++){
        for (int j = 0; j < nb_columns; j++){
            int value;
            printf("Enter the value for column %d:\n", j);
            scanf("%d", &value);
            insert_value(dataframe->columns[j], &value);
        }
    } return;
}

// Fonction qui affiche un dataframe avec un nombre limité de lignes
// Ses paramètres sont un pointeur sur le dataframe et le nombre de lignes à afficher.
// Elle ne retourne rien.
void print_dataframe_limited_rows(CDataframe* df, int limit){
    if (limit > df->nb_rows){
        limit = df->nb_rows;
    }
    for (int i = 0; i < limit; i++){
        printf("[%d]\t", i);
        for (int j = 0; j < df->nb_columns; j++){
            void* value = get_cell_value(df, i, j);
            if (value != NULL){
                switch (df->columns[j]->type){
                    case INT:
                        printf("%d\t", *(int*)value);
                        break;
                    case FLOAT:
                        printf("%.4f\t", *(float*)value);
                        break;
                    case STRING:
                        printf("%s\t", (char*)value);
                        break;
                }
            } else {
                printf("NULL\t");
            }
        }
        printf("\n");
    }

}

// Fonction qui affiche un dataframe avec un nombre limité de colonnes
// Ses paramètres sont un pointeur sur le dataframe et le nombre de colonnes à afficher.
// Elle ne retourne rien.
void print_dataframe_limited_columns(CDataframe* df, int limit){
    if (limit > df->nb_columns){
        limit = df->nb_columns;
    }
    for (int i = 0; i < limit; i++){
        printf("%s\t", df->columns[i]->name);
    }
}

// Fonction qui ajoute une ligne à un dataframe
// Ses paramètres sont un pointeur sur le dataframe et un tableau de valeurs.
// Elle ne retourne rien.
void add_row (CDataframe* df, void** row_values){
    for (int i = 0; i < df->nb_columns; i++){
        insert_value(df->columns[i], row_values[i]);
    }
    df->nb_rows++;
}

// Fonction qui supprime une ligne d'un dataframe
// Ses paramètres sont un pointeur sur le dataframe et l'index de la ligne à supprimer.
// Elle ne retourne rien.
void delete_row(CDataframe* df, int row_to_delete) {
    for (int i = 0; i < df->nb_columns; i++) {
        delete_value_at_index(df->columns[i], row_to_delete);
    }
    df->nb_rows--;
}

// Fonction qui affiche un dataframe après avoir supprimé une ligne
// Ses paramètres sont un pointeur sur le dataframe et l'index de la ligne à supprimer.
// Elle ne retourne rien.
void delete_row_print(CDataframe* df, int row_to_delete) {
    delete_row(df, row_to_delete);
    print_dataframe(df);
}


// Fonction qui supprime une valeur à un index donné
// Ses paramètres sont un pointeur sur la colonne et l'index de la valeur à supprimer.
// Elle ne retourne rien.
void delete_value_at_index(Column* column, int index) {
    if (index < 0 || index >= column->size) {
        printf("Index out of range.\n");
        return;
    }
    for (int i = index; i < column->size - 1; i++) {
        column->values[i] = column->values[i + 1];
    }
    column->values = realloc(column->values, (column->size - 1) * sizeof(void*));
    column->size--;
}