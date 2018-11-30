//
// Created by alexa on 16/11/2018.
//

#include <stdlib.h>
#include "maze.h"
#include "fase1.h"

void solveMaze(char **matrix, char **word) {
    puts("\nMaze.c\n");
    printf("\nNumero de palavras: %d, Numero de linhas: %d", NW, NL);
    int nwordf=0;
    char **spath = NULL;
    for (int k = 0; k < NW; ++k) {
        for (int j = 0; j < NL; ++j) {
            for (int i = 0; i < NL; ++i) {
                if (*(*(matrix+j)+i)==*(*(word+k))){
                    char **path = init_dynmatrix_chars((strlen(*(word+k))+2));
                    *(path+0)=create_copy_dyn_array(*(word+k));
                    char buffer[20];
                    snprintf(buffer, sizeof(buffer), "[%d - %d]", j, i);
                    *(path+1) = create_copy_dyn_array(buffer);
                    find_path(matrix, *(word+k), j, i, 1, path, spath, &nwordf);
                    //printf("\n%d", nwordf);
                    if(spath!=NULL) {
                        printf("\n%s", *(spath + nwordf));
                    }
                }
            }
        }
    }
}


/* Função recursiva para resolver o labirinto */
int find_path(char **matrix, char *word, int l, int c, int temp, char **path, char **spath, int *k) {
    // if (l,c chegou ao fim) return true
    if(temp>=strlen(word) ){
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "[%d - %d]", l, c);
        *(path+2) = create_copy_dyn_array(buffer);
        spath=print_path(path, spath, (strlen(word)+2), *k);
        free(path);
        *k=*k+1;
        return 1;
    }

    //Cima
    if (check_consistency(matrix, word, l - 1, c ,temp)) {
        char *buffer="N";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l - 1, c, temp+1, path, spath, k);

    }
    //Cima-Direita
    if (check_consistency(matrix, word, l - 1, c + 1 , temp)) {
        char *buffer="NE";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l - 1, c + 1, temp+1, path, spath, k);
    }
    //Direita
    if (check_consistency(matrix, word, l, c + 1 , temp)) {
        char *buffer="E";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l, c+1, temp+1, path, spath, k);
    }
    //Baixo-Direita
    if (check_consistency(matrix, word, l + 1, c + 1 , temp)) {
        char *buffer="SE";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l + 1, c+1, temp+1, path, spath, k);
    }
    //Baixo
    if (check_consistency(matrix, word, l +1, c , temp)) {
        char *buffer="S";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l + 1, c, temp+1, path, spath, k);
    }
    //Baixo-Esquerda
    if (check_consistency(matrix, word, l +1, c - 1 , temp)) {
        char *buffer="SW";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l + 1, c - 1, temp+1, path, spath, k);
    }
    //Esquerda
    if (check_consistency(matrix, word, l, c-1 , temp)) {
        char *buffer="W";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l, c-1, temp+1, path, spath, k);
    }
    //Cima-Esquerda
    if (check_consistency(matrix, word, l - 1, c-1 , temp)) {
        char *buffer="NW";
        *(path + temp+2)=create_copy_dyn_array(buffer);
        find_path(matrix, word, l-1, c-1, temp+1, path, spath, k);
    }
    return 0;
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

char **print_path(char **str, char **spath, int n, int k){
    printf("\n");
    char aux[M100];
    for (int i = 0; i < n; i++) {
        if (i == 0){//palavra
            snprintf(aux, sizeof(aux), "%s - ", *(str+i));
//            printf("%s - ", *(str+i));
        }
        else if(i == 1){//posicao inicial
            snprintf(aux, sizeof(aux), "%s %s -> ", aux, *(str+i));
//            printf("%s -> ", *(str+i));
        }
        else if(i == 2){//posicao final
            snprintf(aux, sizeof(aux), "%s %s - ", aux, *(str+i));
//            printf("%s - ", *(str+i));
        }
        else if (i == 3 && strlen(*(str))==2){//primeira direcao
            snprintf(aux, sizeof(aux), "%s DIRECAO: %s ", aux, *(str+i));
//            printf("DIRECAO: %s ", *(str+i));
        }
        else if (i == 3 && strlen(*(str))>2){//primeira direcao
            snprintf(aux, sizeof(aux), "%s DIRECAO: %s -> ", aux, *(str+i));
//            printf("DIRECAO: %s -> ", *(str+i));
        }
        else if(i == n-1){//ultima direcao
            snprintf(aux, sizeof(aux), "%s %s", aux, *(str+i));
//            printf("%s", *(str+i));
        }
        else {//restantes direcoes
            snprintf(aux, sizeof(aux), "%s %s -> ", aux, *(str+i));
//            printf("%s -> ", *(str+i));
        }
    }
    //printf("\n%s", aux);
    spath=resize_dynarray_chars(spath, k-1, k);
//    *(spath+k)=create_copy_dyn_array(aux);
    return spath;
}

/* A utility function to print solution matrix sol[N5][N5] */
void print_mat(int sol[2][10]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

char **resize_dynarray_chars(char **pchar, int size, int newSize){
    char **ptr=init_dynmatrix_chars(newSize);
    if (size!=0){
        for (int i = 0; i < size; ++i) {
            *(ptr + i) = create_copy_dyn_array(*(pchar + i));
        }
        char *paux = NULL;
        for (int i = size; i < newSize; ++i) {
            *(ptr + i) = paux;
        }
        free(pchar);
    }
    return ptr;
}