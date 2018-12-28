#include <stdio.h>
#include <malloc.h>
#include "project/maze.h"
#include "project/matrix.h"
#include "project/fase1.h"
#include "project/fase2.h"
#include "project/fase2/words.h"

void header();
void clearscr ();

int main() {
	puts("Projeto LP1 & AED1\n");
	char mpath[]="D:\\Universidade\\4Ano\\project_aed_lp\\recursos\\matrix.txt";
	char wenpath[]="D:\\Universidade\\4Ano\\project_aed_lp\\recursos\\en_words.txt";
	char wpath[]="D:\\Universidade\\4Ano\\project_aed_lp\\recursos\\words.txt";
	char **words=NULL;
	char **matrix=NULL;
	int op=-1;
	while(op!=0) {
		header();
		scanf("%d", &op);
		switch (op){
			case 1:
				words=read_words_file(words, wpath);
				break;
			case 11:
				words=read_words_file(words, wenpath);
				break;
			case 2:
				matrix=read_matrix_file(matrix, mpath);
				break;
			case 3:
				puts("Insira o numero de linhas e colunas\n");
				scanf("%d %d", &NL, &NC);
				matrix=create_matrix_random(matrix, NL, NC);
				break;
			case 4:
				if (NL==0 || NC==0){
					puts("Ainda não foi criada a matrix!\n");
					break;
				}
				print_dynarray_matrix(matrix, NL, NC);
				break;
			case 5:
				if (NW==0){
					puts("As palavras ainda nao foram importadas!\n");
					break;
				}
				print_dynarray_words(words, NW);
				break;
			case 6:
				if (NW==0){
					puts("As palavras ainda nao foram importadas!\n");
					break;
				}
				words = clienteMSDSORT_WHITHOUT_CUTOFF(words, NW);
				break;
			case 7:
				solveMaze(matrix, words);
			default:break;
		}
	}
    //main_lab_test();
    //fase1();
    //fase2();
	//clientQueues();
    return 0;
}

void header(){
	printf("\n*******************************");
	printf("\n* 1) Ler palavras do ficheiro *");
	printf("\n* 2) Ler matrix do ficheiro   *");
	printf("\n* 3) Gerar matrix             *");
	printf("\n* 4) Imprimir matrix          *");
	printf("\n* 5) Imprimir palavras        *");
	printf("\n* 6) MSD SORT                 *");
	printf("\n* 7) Procurar palavras        *");
	printf("\n*******************************\n");

}