#ifndef MATRIX_C_INCLUDED
#define MATRIX_C_INCLUDED
#include "matrix.h"

/* Cria matriz dinamicamente, aloca a estrutura que representa a matriz */
void matriz_cria(matriz *mat,int m, int n) {
  mat->lin = m;
  mat->col = n;
  //matriz mat = (matriz*) malloc(sizeof(matriz));
  mat->dados = (complexo**) malloc(m*sizeof(complexo*));
  int i;
  for (i=0; i<m; i++){
    mat->dados[i] = (complexo*) malloc(n*sizeof(complexo));
  }
}

void matriz_ler_arquivo(matriz *mat, FILE *input) {
  char aux[1000];
  int i,j;

  for(i = 0; i < mat->lin; i++) {
    for(j = 0; j < mat->col; j++) {
      fscanf(input, "%s", aux);
      mat->dados[i][j] = ler_complexo(aux); /*Tratamento dos números complexos lidos nas posições da matriz*/
    }
  }
}

/*Função que faz a multiplicao das matrizes complexas*/
void matriz_multiplica(matriz *prod, matriz *a, matriz *b) {
  complexo soma,produto;
  int i,j,k;
  /*Complexidade O(n³)*/
	matriz_cria(prod, a->lin, b->col);
	for(i = 0; i < a->lin ; i++){
    for(j = 0; j < b->col; j++){
      soma = inicializar_complexo(0,0);
      for(k = 0; k < a->col; k++){
        produto = multiplica_complexo(a->dados[i][k], b->dados[k][j]);
        soma = soma_complexo(soma, produto);
      }
      prod->dados[i][j] = soma;
    }
	}
}

/*Função que grava a matriz no arquivo*/
void matriz_exporta(matriz *produto, FILE *output) {
  int i,j;

  for(i = 0; i < produto->lin; i++) {
    for(j = 0; j < produto->col ; j++) {
      escreve_complexo(produto->dados[i][j], output);
      fprintf(output," ");
    }
    fprintf(output,"\n");
  }
}

/* Libera memória da matriz alocada */
void libera_matriz(matriz* mat){
  int i;
  for(i=0; i<mat->lin; i++){
    free(mat->dados[i]);
  }
  free(mat->dados);
}
#endif // MATRIX_C_INCLUDED
