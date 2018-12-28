//
// Created by alexa on 16/11/2018.
//

#include <stdlib.h>
#include "maze.h"
#include "fase1.h"

void solveMaze(char **matrix, char **word) {
    puts("\nMaze.c\n");
    printf("\nNumero de palavras: %d, Numero de linhas: %d, Numero de colunas: %d", NW, NL, NC);
    int **spath=NULL;
    for (int k = 0; k < NW; ++k) {
        for (int j = 0; j < NL; ++j) {
            for (int i = 0; i < NC; ++i) {
                if (*(*(matrix+j)+i)==*(*(word+k))){
                    char **path = init_dynmatrix_chars((strlen(*(word+k))+2));
                    int *paux = create_dynarray_ints(strlen(*(word+k))+4);
                    paux[0]=k;
                    *(path+0)=create_copy_dyn_array(*(word+k));
                    char buffer[20];
                    paux[1]=j;
                    paux[2]=i;
                    snprintf(buffer, sizeof(buffer), "[%d - %d]", j, i);
                    *(path+1) = create_copy_dyn_array(buffer);
                    spath=find_path(matrix, *(word+k), j, i, 1, path, spath, paux);
                }
            }
        }
    }
}


/* Função recursiva para resolver o labirinto */
int **find_path(char **matrix, char *word, int l, int c, int temp, char **path, int **spath, int *paux) {
    // if (l,c chegou ao fim) return true
    if(temp>=strlen(word) ){
        paux[sizeof(paux)-2]=l;
        paux[sizeof(paux)-1]=c;
        //spath=create_or_resize_dynmatrix_int(spath, paux);
//        print_spath(spath);
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "[%d - %d]", l, c);
        *(path+2) = create_copy_dyn_array(buffer);
        print_path(path, strlen(word)+2);
        return spath;
    }

    //Cima
    if (check_consistency(matrix, word, l - 1, c ,temp)) {
        char *buffer="N";
        paux[temp+2]=0;
        *(path + temp+2)=create_copy_dyn_array(buffer);
        spath=find_path(matrix, word, l - 1, c, temp+1, path, spath, paux);
        return spath;
    }
    //Cima-Direita
    if (check_consistency(matrix, word, l - 1, c + 1 , temp)) {
        char *buffer="NE";
        paux[temp+2]=1;
        *(path + temp+2)=create_copy_dyn_array(buffer);
        spath=find_path(matrix, word, l - 1, c + 1, temp+1, path, spath, paux);
        return spath;
    }
    //Direita
    if (check_consistency(matrix, word, l, c + 1 , temp)) {
        char *buffer="E";
        paux[temp+2]=2;
        *(path + temp+2)=create_copy_dyn_array(buffer);
        spath=find_path(matrix, word, l, c+1, temp+1, path, spath, paux);
        return spath;
    }
    //Baixo-Direita
    if (check_consistency(matrix, word, l + 1, c + 1 , temp)) {
        char *buffer="SE";
        paux[temp+2]=3;
        *(path + temp+2)=create_copy_dyn_array(buffer);
        spath=find_path(matrix, word, l + 1, c+1, temp+1, path, spath, paux);
        return spath;
    }
    //Baixo
    if (check_consistency(matrix, word, l +1, c , temp)) {
        char *buffer="S";
        paux[temp+2]=4;
        *(path + temp+2)=create_copy_dyn_array(buffer);
        spath=find_path(matrix, word, l + 1, c, temp+1, path, spath, paux);
        return spath;
    }
    //Baixo-Esquerda
    if (check_consistency(matrix, word, l +1, c - 1 , temp)) {
        char *buffer="SW";
        paux[temp+2]=5;
        *(path + temp+2)=create_copy_dyn_array(buffer);
        spath=find_path(matrix, word, l + 1, c - 1, temp+1, path, spath, paux);
        return spath;
    }
    //Esquerda
    if (check_consistency(matrix, word, l, c-1 , temp)) {
        char *buffer="W";
        paux[temp+2]=6;
        *(path + temp+2)=create_copy_dyn_array(buffer);
        spath=find_path(matrix, word, l, c-1, temp+1, path, spath, paux);
        return spath;
    }
    //Cima-Esquerda
    if (check_consistency(matrix, word, l - 1, c-1 , temp)) {
        char *buffer="NW";
        paux[temp+2]=7;
        *(path + temp+2)=create_copy_dyn_array(buffer);
        spath=find_path(matrix, word, l-1, c-1, temp+1, path, spath, paux);
        return spath;
    }
    return spath;
}

/* Verifica se as coordenadas ainda estão dentro do labirinto */
int check_consistency(char **matrix, char *words, int l, int c, int temp){
    // if (l,c fora do labirinto) devolve falso
    if (l >= 0 && l < NL && c >= 0 && c < NC)
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
        else if (i == 3 && strlen(*(str))==2){//primeira direcao
            printf("DIRECAO: %s ", *(str+i));
        }
        else if (i == 3 && strlen(*(str))>2){//primeira direcao
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

void print_spathv2(int *spath){
    if(spath!=NULL) {
        puts("\n");
            for (int i = 0; i < sizeof(spath); ++i) {
                printf("%d\t", *(spath + i));
            }
    } else puts("\nspath is null!");
}

void print_spath(int **spath){
    if(spath!=NULL) {
        puts("\n");
        for (int j = 0; j<(sizeof(spath)/*/sizeof(*(spath+j))*/); ++j) {
            for (int i = 0; i<sizeof(*(spath+j)); ++i) {
                printf("%d\t", *(*(spath + j) + i));
            }
        }
    } else puts("\nspath is null!");
}
int write_file(char **matrix, int **result){
    FILE *fp;
    if((fp = fopen( "D:\\Universidade\\4Ano\\project_aed_lp\\recursos\\results.txt" , "wb" )) == NULL) /* Abre arquivo binário para escrita */
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    char space=' ';
    char enter[]="\n";
    fwrite(&space, sizeof(char), sizeof(space), fp);
    printf("%-4c", ' ');
    for (int j = 0; j < (sizeof(matrix)/ sizeof(*(matrix))); ++j) {
        fwrite(&j, sizeof(int), sizeof(j), fp);
    }
    fwrite(&enter, sizeof(char), sizeof(enter), fp);
    for (int i = 0; i < (sizeof(matrix)/ sizeof(*(matrix))); ++i) {
        fwrite(&i, sizeof(int), sizeof(i), fp);
        for (int j = 0; j < (sizeof(matrix)/ sizeof(*(matrix))); ++j) {
            fwrite(&*(*(matrix + j) + i), sizeof(char), sizeof(*(*(matrix + j) + i)), fp);
        }
        fwrite(&enter, sizeof(char), sizeof(enter), fp);
    }
    fclose(fp);
    return(1);
}