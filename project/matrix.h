//
// Created by alexa on 22/11/2018.
//

#ifndef PROJECT_AED_LP_FILES_H
#define PROJECT_AED_LP_FILES_H
#define M100 100

char **init_dynmatrix_chars(int lines);

char **read_words_file(char **paux, const char *path);
char **read_matrix_file(char **paux, const char *path);
char *create_copy_dyn_array(char *str);
void print_dynarray_words(char **str, int nl);
void print_dynarray_matrix(char **str, int nl, int nc);
char **create_matrix_random(char **paux, int nl, int nc);
int **init_dynmatrix_ints(int lines);
int *using_malloc_create_dynarray_ints(int n);
int **resize_dynarray_ints(int **pints, int size, int newSize);
int **create_or_resize_dynmatrix_int(int **ppi, int *path);
int *create_dynarray_ints(int size);
#endif //PROJECT_AED_LP_FILES_H
