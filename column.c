// Commentaire column.c
// CDataframe
// Justine GARNUNG et Yéléna SAINTE-ROSE BRUNY
// Rôle : Implémentation des fonctions de la structure Column.

//Utilisation d'une colonne pouvant stocker plusieurs types de données et pas seulement des entiers.

#include "column.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Fonction qui crée une colonne,
// Ses paramètres sont un pointeur sur la colonne à créer, le nom de la colonne et le type de données qu'elle contiendra.
// Elle ne retourne rien.
void create_column(Column* column, char* name, int type){
    column->name = strdup(name);
    column->type = type;
    column->size = 0;
    if (type == 0){
        column->int_data = NULL;
    } else if (type == 1){
        column->string_data = NULL;
    } else {
        column->double_data = NULL;
    }
}

// Fonction qui insère une valeur dans une colonne
// Ses paramètres sont un pointeur sur la colonne dans laquelle on veut insérer la valeur et la valeur à insérer.
// Elle retourne 1 si l'insertion a réussi et 0 sinon.
int insert_value(Column* column, void* value){
    if (column->size % 256 == 0){
        if (column->type == 0){
            column->int_data = realloc(column->int_data, (column->size + 256) * sizeof(int));
            if (column->int_data == NULL) return 0;
            column->int_data[column->size] = *(int*)value;
        } else if (column->type == 1){
            column->string_data = realloc(column->string_data, (column->size + 256) * sizeof(char*));
            if (column->string_data == NULL) return 0;
            column->string_data[column->size] = strdup((char*)value);
        } else {
            column->double_data = realloc(column->double_data, (column->size + 256) * sizeof(double));
            if (column->double_data == NULL) return 0;
            column->double_data[column->size] = *(double*)value;
        }
    } else {
        if (column->type == 0){
            column->int_data[column->size] = *(int*)value;
        } else if (column->type == 1){
            column->string_data[column->size] = strdup((char*)value);
        } else {
            column->double_data[column->size] = *(double*)value;
        }
    }

    column->size++;

    return 1;
}

// Fonction qui affiche les valeurs d'une colonne, ses paramètres sont un pointeur sur la colonne à afficher
// Elle ne retourne rien.
void print_col(Column* column){
    for (int i = 0; i < column->size; i++){
        printf("[%d] ", i);
        if (column->type == 0){
            printf("%d\n", column->int_data[i]);
        } else if (column->type == 1){
            printf("%s\n", column->string_data[i]);
        } else {
            printf("%f\n", column->double_data[i]);
        }
    }
}


// Fonction qui supprime une colonne, ses paramètres sont un pointeur sur la colonne à supprimer et elle ne retourne rien.
void delete_column(Column** column){
    if ((*column)->type == 0 && (*column)->int_data != NULL) {
        free((*column)->int_data);
    }
    if ((*column)->type == 1 && (*column)->string_data != NULL) {
        for (int j = 0; j < (*column)->size; j++) {
            free((*column)->string_data[j]);
        }
        free((*column)->string_data);
    }
    if ((*column)->type == 2 && (*column)->double_data != NULL) {
        free((*column)->double_data);
    }
    free((*column)->name);
    free(*column);
    *column = NULL;
}

// Fonction qui compte le nombre de fois qu'une valeur est présente dans une colonne.
// Ses paramètres sont un pointeur sur la colonne et la valeur à chercher.
// Elle retourne le nombre de fois que la valeur est présente.
int count_value(Column* column, void* value){
    int count = 0;
    for (int i = 0; i < column->size; i++){
        if (column->type == 0 && column->int_data[i] == *(int*)value){
            count++;
        } else if (column->type == 1 && strcmp(column->string_data[i], (char*)value) == 0){
            count++;
        } else if (column->type == 2 && column->double_data[i] == *(double*)value){
            count++;
        }
    }
    return count;
}

// Fonction qui retourne la valeur à l'index donné dans une colonne.
// Ses paramètres sont un pointeur sur la colonne et l'index de la valeur à retourner.
// Elle retourne un pointeur sur la valeur.
void* get_value(Column* column, int index){
    if (index < 0 || index >= column->size){
        return NULL;
    }
    if (column->type == 0){
        return &(column->int_data[index]);
    } else if (column->type == 1){
        return column->string_data[index];
    } else {
        return &(column->double_data[index]);
    }
}

// Fonction qui compte le nombre de valeurs supérieures à une valeur donnée dans une colonne.
// Ses paramètres sont un pointeur sur la colonne et la valeur à comparer.
// Elle retourne le nombre de valeurs supérieures.
int count_greater_than(Column* column, void* value){
    int count = 0;
    for (int i = 0; i < column->size; i++){
        if (column->type == 0 && column->int_data[i] > *(int*)value){
            count++;
        } else if (column->type == 1 && strcmp(column->string_data[i], (char*)value) > 0){
            count++;
        } else if (column->type == 2 && column->double_data[i] > *(double*)value){
            count++;
        }
    }
    return count;
}

// Fonction qui compte le nombre de valeurs inférieures à une valeur donnée dans une colonne.
// Ses paramètres sont un pointeur sur la colonne et la valeur à comparer.
// Elle retourne le nombre de valeurs inférieures.
int count_less_than(Column* column, void* value){
    int count = 0;
    for (int i = 0; i < column->size; i++){
        if (column->type == 0 && column->int_data[i] < *(int*)value){
            count++;
        } else if (column->type == 1 && strcmp(column->string_data[i], (char*)value) < 0){
            count++;
        } else if (column->type == 2 && column->double_data[i] < *(double*)value){
            count++;
        }
    }
    return count;
}

// Fonction qui met à jour la valeur à l'index donné dans une colonne.
// Ses paramètres sont un pointeur sur la colonne, l'index de la valeur à mettre à jour et la nouvelle valeur.
// Elle ne retourne rien.
void update_value(Column* column, int index, void* value) {
    if (index < 0 || index >= column->size) {
        printf("Index out of range.\n");
        return;
    }
    if (column->values[index] != NULL) {
        free(column->values[index]);
    }
    column->values[index] = value;
}