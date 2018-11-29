//
// Created by alexa on 16/11/2018.
//

#ifndef PROJECT_AED_LP_MAZE_H
#define PROJECT_AED_LP_MAZE_H


#include<stdio.h>
#include <mem.h>
#include "matrix.h"
// Maze size
#define N5 5
#define M20 20

void solveMaze(char **matrix, char **word);
void print_mat(int sol[2][10]);
int check_consistency(char **matrix, char *words, int l, int c,int temp);
int find_path(char **matrix, char *word, int l, int c, int temp, char **path, char **spath, int *k);
void print_path(char **str, int n, int k);
char **resize_dynarray_chars(char **pchar, int size, int newSize);
#endif //PROJECT_AED_LP_MAZE_H
