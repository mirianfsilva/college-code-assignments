#ifndef MATRIZCOMPLEXA_H_INCLUDED
#define MATRIZCOMPLEXA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

typedef struct matriz{
  int lin;
  int col;
  complexo** dados;
} matriz;

void matriz_ler_arquivo(matriz *mat, FILE *input); /*Função que ler a matriz do arquivo*/
void matriz_cria(matriz *mat, int m, int n);
void matriz_multiplica(matriz *prod, matriz *a, matriz *b); /* função que multiplica as matrizes complexas*/
void matriz_exporta(matriz *produto, FILE *output); /*Função que grava a matriz no arquivo*/
void libera_matriz(matriz *mat);

#endif // MATRIZCOMPLEXA_H_INCLUDED
