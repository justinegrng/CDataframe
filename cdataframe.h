#ifndef PROJET_LANGAGE_C_CDATAFRAME_H
#define PROJET_LANGAGE_C_CDATAFRAME_H

#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Column Column;

typedef struct {
    Column** columns;
    int size;
    int nb_rows;
    int nb_columns;
} CDataframe;

void create_cdataframe(CDataframe* dataframe);
void add_column(CDataframe* dataframe, Column* column);
void delete_column_at_index(CDataframe* dataframe, int index);
void rename_column(CDataframe* dataframe, int index, char* new_name);
int find_value(CDataframe* dataframe, void* value);
void* get_cell_value(CDataframe* dataframe, int row, int col);
void set_cell_value(CDataframe* dataframe, int row, int col, void* value);
void print_column_names(CDataframe* dataframe);
int count_rows(CDataframe* dataframe);
int count_columns(CDataframe* dataframe);
int count_cells_equal(CDataframe* dataframe, void* value);
int count_cells_greater(CDataframe* dataframe, void* value);
int count_cells_less(CDataframe* dataframe, void* value);
void print_dataframe(CDataframe* dataframe);
void create_print_df();
void fill_dataframe_user(CDataframe* dataframe);
void delete_value_at_index(Column* column, int index);
void delete_row(CDataframe* dataframe, int row_index);
void add_row(CDataframe* dataframe, void** values);
void print_dataframe_limited_columns(CDataframe* dataframe, int limit);
void print_dataframe_limited_rows(CDataframe* dataframe, int limit);
void delete_row_print(CDataframe* dataframe, int row_index);


#endif //PROJET_LANGAGE_C_CDATAFRAME_H