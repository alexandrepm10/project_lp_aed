//
// Created by alexa on 16/11/2018.
//

#include <stdlib.h>
#include "maze.h"

void solveMaze(char **matrix, char **word) {
    puts("\nMaze.c\n");
    for (int k = 0; k < 5; ++k) {
        char **path = init_dynmatrix_chars((strlen(*(word+k))+2));
        *(path)=create_copy_dyn_array(*(word+k));
        for (int j = 0; j < N5; ++j) {
            for (int i = 0; i < N5; ++i) {
                if (*(*(matrix+j)+i)==*(*(word+k))){
                    char buffer[20];
                    snprintf(buffer, sizeof(buffer), "[%d - %d]", j, i);
                    *(path+1) = create_copy_dyn_array(buffer);
                    find_path(matrix, *(word+k), j, i, 1, path);
                }
            }
        }
    }
}


/* Função recursiva para resolver o labirinto */
void find_path(char **matrix, char *word, int l, int c, int temp, char **path) {
    // if (l,c chegou ao fim) return true
    if(word[temp]=='\n' ){
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "[%d - %d]", l, c);
        *(path+2) = create_copy_dyn_array(buffer);
        print_path(path, strlen(word)+1);
        return;
    }

    //Cima
    if (check_consistency(matrix, word, l - 1, c ,temp)) {
        char *buffer="N";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l - 1, c, temp+1, path);

    }
    //Cima-Direita
    if (check_consistency(matrix, word, l - 1, c + 1 , temp)) {
        char *buffer="NE";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l - 1, c + 1, temp+1, path);
    }
    //Direita
    if (check_consistency(matrix, word, l, c + 1 , temp)) {
        char *buffer="E";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l, c+1, temp+1, path);
    }
    //Baixo-Direita
    if (check_consistency(matrix, word, l + 1, c + 1 , temp)) {
        char *buffer="SE";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l + 1, c+1, temp+1, path);
    }
    //Baixo
    if (check_consistency(matrix, word, l +1, c , temp)) {
        char *buffer="S";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l + 1, c, temp+1, path);
    }
    //Baixo-Esquerda
    if (check_consistency(matrix, word, l +1, c - 1 , temp)) {
        char *buffer="SW";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l + 1, c - 1, temp+1, path);
    }
    //Esquerda
    if (check_consistency(matrix, word, l, c-1 , temp)) {
        char *buffer="W";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l, c-1, temp+1, path);
    }
    //Cima-Esquerda
    if (check_consistency(matrix, word, l - 1, c-1 , temp)) {
        char *buffer="NW";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l-1, c-1, temp+1, path);
    }
}

/* Verifica se as coordenadas ainda estão dentro do labirinto */
int check_consistency(char **matrix, char *words, int l, int c, int temp){
    // if (l,c fora do labirinto) devolve falso
    if (l >= 0 && l < N5 && c >= 0 && c < N5)
        if (*(*(matrix+l)+c)==*(words+temp)) {
            return 1;
        }
    return 0;
}

void print_path(char **str, int n){
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (i == 0){//palavra
            printf("%s - ", *(str+i));
        }
        else if(i == 1){//posicao inicial
            printf("%s -> ", *(str+i));
        }
        else if(i == 2){//posicao final
            printf("%s - ", *(str+i));
        }
        else if (i == 3){//primeira direcao
            printf("DIRECAO: %s -> ", *(str+i));
        }
        else if(i == n-1){//ultima direcao
            printf("%s", *(str+i));
        }
        else {//restantes direcoes
            printf("%s -> ", *(str+i));
        }
    }
}

/* A utility function to print solution matrix sol[N5][N5] */
void print_mat(int sol[2][10]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}