//
// Created by alexa on 22/11/2018.
//

#include "fase1.h"

void fase1() {
    char mpath[]="D:\\Universidade\\4Ano\\project_aed_lp\\recursos\\matrix.txt";
    char wpath[]="D:\\Universidade\\4Ano\\project_aed_lp\\recursos\\words.txt";
    char **words=NULL;
    int NW=0;
    int NL=0;
    words=read_words_file(words, &NW, wpath);
    print_dynarray_words(words, NW);

    char **matrix=NULL;
    matrix=read_words_file(words, &NL, mpath);;
    puts("\nSopa de letras\n");
    print_dynarray_matrix(matrix, NL);
    words = clienteMSDSORT_WHITHOUT_CUTOFF(words, NW);
    print_dynarray_words(words, NW);

    solveMaze(matrix, words);

}