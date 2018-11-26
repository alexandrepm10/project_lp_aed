//
// Created by alexa on 16/11/2018.
//

#include <stdlib.h>
#include "maze.h"

void solveMaze(char **matrix, char **word) {
    puts("\nMaze.c\n");
    char maux[10], waux[10];
    for (int k = 0; k < 5; ++k) {
        strcpy(waux, *(word+k));
        //puts(waux);
        for (int j = 0; j < N5; ++j) {
            strcpy (maux,*(matrix+j));
            //puts(maux);
            for (int i = 0; i < N5; ++i) {
                if (waux[0]==maux[i]){
                    //printf("\nA procurar palavra %s\t iniciais w:%c\tm:%c", waux, waux[0], maux[i]);
                    find_path(matrix, waux, j, i, 0);
                }
            }
        }
    }
}


/* Função recursiva para resolver o labirinto */
void find_path(char **matrix, char *word, int l, int c, int temp) {
    temp++;
    // if (l,c chegou ao fim) return true
    if(word[temp]=='\n' ){
        printf("\nPalavra %s, l=%d, c=%d", word, l, c);
        puts("\nFim palavra");
        return;
    }

    //Cima
    if (check_consistency(matrix, word, l - 1, c ,temp)) {
        printf("\nPalavra %s\tl=%d, c=%d", word, l, c);
        find_path(matrix, word, l - 1, c, temp);
        temp--;
        return;

    }
    //Cima-Direita
    if (check_consistency(matrix, word, l - 1, c + 1 , temp)) {
        printf("\nPalavra %s\tl=%d, c=%d", word, l, c);
        find_path(matrix, word, l - 1, c + 1, temp);
        temp--;
        return;
    }
    //Direita
    if (check_consistency(matrix, word, l, c + 1 , temp)) {
        printf("\nPalavra %s\tl=%d, c=%d", word, l, c);
        find_path(matrix, word, l, c+1, temp);
        temp--;
        return;
    }
    //Baixo-Direita
    if (check_consistency(matrix, word, l + 1, c + 1 , temp)) {
        printf("\nPalavra %s\tl=%d, c=%d", word, l, c);
        find_path(matrix, word, l + 1, c+1, temp);
        temp--;
        return;
    }
    //Baixo
    if (check_consistency(matrix, word, l +1, c , temp)) {
        printf("\nPalavra %s\tl=%d, c=%d", word, l, c);
        find_path(matrix, word, l + 1, c, temp );
        temp--;
        return;
    }
    //Baixo-Esquerda
    if (check_consistency(matrix, word, l +1, c - 1 , temp)) {
        printf("\nPalavra %s\tl=%d, c=%d", word, l, c);
        find_path(matrix, word, l + 1, c - 1, temp );
        temp--;
        return;
    }
    //Esquerda
    if (check_consistency(matrix, word, l, c-1 , temp)) {
        printf("\nPalavra %s\tl=%d, c=%d", word, l, c);
        find_path(matrix, word, l, c-1, temp );
        temp--;
        return;
    }
    //Cima-Esquerda
    if (check_consistency(matrix, word, l - 1, c-1 , temp)) {
        printf("\nPalavra %s\tl=%d, c=%d", word, l, c);
        find_path(matrix, word, l-1, c-1, temp);
        temp--;
        return;
    }
}

/* Verifica se as coordenadas ainda estão dentro do labirinto */
int check_consistency(char **matrix, char *words, int l, int c, int temp){
    char aux[100];
    // if (l,c fora do labirinto) devolve falso
    if (l >= 0 && l < N5 && c >= 0 && c < N5)
        strcpy(aux, (*(matrix+l)));
        if (aux[c]==*(words+temp)) {
            return 1;
        }
    return 0;
}

/* A utility function to print solution matrix sol[N5][N5] */
void print_mat(int sol[2][10]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}