//
// Created by alexa on 22/11/2018.
//

#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "fase1.h"

char **init_dynmatrix_chars(int lines) {
    char **ppaux = (char **) malloc(sizeof(char *) * lines);
    char *paux = NULL;
    for (int i = 0; i < lines; ++i) {
        *(ppaux + i) = paux;
        }
    return ppaux;
}
char **read_words_file(char **paux, const char *path){
    char aux[M100];
    FILE *fp;
    fp = fopen(path, "r");
    if (fp==NULL){
        printf("\nErro abrir o ficheiro!!");
    } else {
        printf("\nFicheiro 'words' aberto com sucesso");
        fscanf(fp, "%d", &NW);
        printf("\n%d\n", NW);
        paux=init_dynmatrix_chars(NW);
        for (int i = 0; i <= NW; ++i) {
            //fgets(aux, sizeof(aux), fp);
            if (fgets(aux, sizeof aux, fp) != NULL) {
                size_t len = strlen(aux);
                if (len > 0 && aux[len - 1] == '\n') {
                    aux[--len] = '\0';
                }
            }
            //fscanf(fp, "%s", aux);
            *(paux + i) = create_copy_dyn_array(strupr(aux));
        }
        fclose(fp);
    }
    return paux;
}

char **read_matrix_file(char **paux, const char *path){
    char aux[M100];
    FILE *fp;
    fp = fopen(path, "r");
    if (fp==NULL){
        printf("\nErro abrir o ficheiro!!");
    } else {
        printf("\nFicheiro 'Matrix' aberto com sucesso");
        fscanf(fp, "%d%d", &NL, &NC);
        printf("\n%d %d\n", NL, NC);
        paux=init_dynmatrix_chars(NL);
        for (int i = 0; i <= NL; ++i) {
            if (fgets(aux, sizeof aux, fp) != NULL) {
                size_t len = strlen(aux);
                if (len > 0 && aux[len - 1] == '\n') {
                    aux[--len] = '\0';
                }
            }
            *(paux + i) = create_copy_dyn_array(strupr(aux));
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
        printf("\nPalavra n[%d]:\t%s",i+1,  *(str+i));
    }
}

void print_dynarray_matrix(char **str, int nl, int nc){
    char *aux=NULL;
    printf("%-4c", ' ');
    for (int j = 0; j < nc; ++j) {
        printf("%-4d ", j);
    }
    printf("\n");
    for (int i = 0; i < nl; ++i) {
        aux=*(str+i);
        printf("%-4d", i);
        for (int j = 0; j < nc; ++j) {
            printf("%-4c ", *(aux + j));
        }
        printf("\n");
    }
}

char **create_matrix_random(char **paux, int nl, int nc){
    char aux[nc];
    time_t t;
    srand((unsigned) time(&t));
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    paux=init_dynmatrix_chars(nl);
    for (int i = 0; i < nl; ++i) {
        for (int j = 0; j < nc; ++j) {
            aux[j]=letters[rand()%26];
        }
        *(paux + i) = create_copy_dyn_array(aux);
    }
    return paux;
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


int **resize_dynarray_ints(int **pints, int size, int newSize){
    int **ptr=init_dynmatrix_ints(newSize);
    for (int i = 0; i < size; ++i) {
        *(ptr+i)=*(pints+i);
    }
    for (int j = size; j < newSize; ++j) {
        *(ptr+j)=0;
    }
    free(pints);
    return ptr;
}

int **create_or_resize_dynmatrix_int(int **ppi, int *path) {
    int **paux;
    if (ppi == NULL) {
        paux = (int **) malloc(sizeof(int *) * 1);
        //paux = init_dynmatrix_ints(1);
        *(paux)=create_dynarray_ints(sizeof(path));
        *(paux) = path;
        return paux;
    }
    paux=init_dynmatrix_ints(sizeof(ppi)+1);            //size é sempre o numero de colunas

    for (int k = 0; k < (sizeof(ppi)/sizeof(*ppi)); ++k) {
            *(paux+k)=*(ppi+k);
    }
    *(paux+(sizeof(ppi)/sizeof(*ppi)))=path;
    free(ppi);
    return paux;
}

int *create_dynarray_ints(int size) {
    int *paux = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        *(paux + i) = 0;
    }
    return paux;
}

