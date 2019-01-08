#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char *argv[]) {
  int instancia,lin,col,i;
  matriz a,b,produto;

	FILE *fin = fopen(argv[1], "r"); // "input.txt" - leitura
  FILE *fout = fopen(argv[2], "w"); // "output.txt" - escrita

  if(fin == NULL || fout == NULL) {
    printf("Erro ao abrir o(s) arquivo(s).");
    return 0;
  }

  fscanf(fin, "%d\n", &instancia); // multiplicações feitas

  for(i = 0; i < instancia ; i++){
	/*Ler arquivo*/
  	/*Recebe matrizes para multiplicação*/
	fscanf(fin, "%d %d", &lin ,&col);
	matriz_cria(&a,lin,col);
	matriz_ler_arquivo(&a,fin);

	fscanf(fin, "%d %d", &lin, &col);
	matriz_cria(&b,lin,col);
	matriz_ler_arquivo(&b,fin);

	matriz_multiplica(&produto,&a,&b);	/*Produto*/
	matriz_exporta(&produto,fout);	/*Exporta Matriz produto para o arquivo*/
	fprintf(fout, "\n");

	/*Desalocar*/
	libera_matriz(&a);
	libera_matriz(&b);
	}

	fclose(fout);
  fclose(fin);
	return 0;
}
