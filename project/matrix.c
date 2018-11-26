//
// Created by alexa on 22/11/2018.
//

#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include <stdlib.h>
#include "matrix.h"

char **init_dynmatrix_chars(int lines) {
    char **ppaux = (char **) malloc(sizeof(char *) * lines);
    char *paux = NULL;
    for (int i = 0; i < lines; ++i) {
        *(ppaux + i) = paux;
        }
    return ppaux;
}
char **read_words_file(char **paux, int *nl, const char *path){
    char aux[M100];
    FILE *fp;
    fp = fopen(path, "r");
    if (fp==NULL){
        printf("\nErro abrir o ficheiro!!");
    } else {
        printf("\nFicheiro 'words' aberto com sucesso");
        fscanf(fp, "%d", nl);
        printf("\n%d\n", *nl);
        paux=init_dynmatrix_chars(*nl);
        for (int i = 0; i <= *nl; ++i) {
            fgets(aux, M100, fp);
            *(paux + i) = create_copy_dyn_array(aux);
        }
        fclose(fp);
    }
    return paux;
}

char *create_copy_dyn_array(char *str){
    char *pc=malloc((strlen(str)+1)* sizeof(char));
    strcpy(pc,str);
    return pc;
}

void print_dynarray_words(char **str, int nl){
    for (int i = 0; i < nl; ++i) {
        printf("\nPalavra n[%d]:\t%s",i,  *(str+i));
    }
}

void print_dynarray_matrix(char **str, int nl){
    char *aux=NULL;
    for (int i = 0; i < nl; ++i) {
        aux=*(str+i);
        for (int j = 0; j < nl; ++j) {
            printf("%c\t", *(aux + j));
        }
        printf("\n");
    }
}

char **create_matrix_random(char **paux, int nl, int nc){
    char aux[M100];
    for (int i = 0; i < nl; ++i) {
        random_string(aux, nc);
        *(paux + i) = create_copy_dyn_array(aux);
    }
    return paux;
}

char* random_string(char *aux, int nchar){
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (int i = 0; i < nchar; ++i) {
        aux[i]=letters[rand()%26];
    }
    return aux;
}



int **init_dynmatrix_ints(int lines) {
    int **ppaux = (int **) malloc(sizeof(int *) * lines);
    int *paux = NULL;
    for (int i = 0; i < lines; ++i) {
        *(ppaux + i) = paux;
    }
    return ppaux;
}

int *using_malloc_create_dynarray_ints(int n) {
    int *ptr=(int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) {
        *(ptr+i)=0;
    }
    return ptr;
    //return calloc(n, sizeof(int));
}