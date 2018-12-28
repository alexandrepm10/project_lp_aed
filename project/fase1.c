//
// Created by alexa on 22/11/2018.
//

#include "fase1.h"

void fase1() {
    char mpath[]="D:\\Universidade\\4Ano\\project_aed_lp\\recursos\\matrix.txt";
    char wpath[]="D:\\Universidade\\4Ano\\project_aed_lp\\recursos\\words.txt";
    char **words=NULL;
    char **matrix=NULL;
//    NL=24;  //numero de linhas/colunas da matrix gerada
//    NC=24
    words=read_words_file(words, wpath);
    //print_dynarray_words(words, NW);

    matrix=read_matrix_file(matrix, mpath);
    //matrix=create_matrix_random(matrix, NL, NC);
    puts("\nSopa de letras\n");
    print_dynarray_matrix(matrix, NL, NC);

    //words = clienteMSDSORT_WHITHOUT_CUTOFF(words, NW);
    print_dynarray_words(words, NW);
    solveMaze(matrix, words);

}