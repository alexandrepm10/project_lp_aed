//
// Created by alexa on 16/11/2018.
//

#ifndef PROJECT_AED_LP_MAZE_H
#define PROJECT_AED_LP_MAZE_H


#include<stdio.h>
#include <mem.h>
#include "matrix.h"

void solveMaze(char **matrix, char **word);
int check_consistency(char **matrix, char *words, int l, int c,int temp);
int ** find_path(char **matrix, char *word, int l, int c, int temp, char **path, int **spath, int *paux);
void print_path(char **str, int n);
void print_spathv2(int *spath);
void print_spath(int **spath);
int write_file(char **matrix, int **result);

#endif //PROJECT_AED_LP_MAZE_H
