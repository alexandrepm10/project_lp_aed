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
void find_path(char **matrix, char *word, int l, int c, int temp);

#endif //PROJECT_AED_LP_MAZE_H
