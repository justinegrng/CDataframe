//
// Created by jugar on 10/04/2024.
//

#ifndef PROJET_LANGAGE_C_COLUMN_H
#define PROJET_LANGAGE_C_COLUMN_H

#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Column {
    char* name;
    int type;
    void** values;
    int size;
    int* int_data;
    char** string_data;
    double* double_data;
} Column;

typedef enum {
    INT,
    STRING,
    FLOAT,
} DataType;

void create_column(Column* column, char* name, int type);
int insert_value(Column* column, void* value);
void print_col(Column* column);
int count_value(Column* column, void* value);
void delete_column(Column** column);
void* get_value(Column* column, int index);
int count_greater_than(Column* column, void* value);
int count_less_than(Column* column, void* value);
void update_value(Column* column, int index, void* value);


#endif //PROJET_LANGAGE_C_COLUMN_H
