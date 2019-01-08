#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct complexo{
  double real;
  double imaginario;
}complexo;

//typedef complexo *Ptcomplexo; /* Ponteiro para a estrutura complexo*/

complexo inicializar_complexo (double real, double imaginario); /* Função que cria e inicializa um complexo na forma a+bi */
complexo ler_complexo(char *str); /*Ler os números complexos na forma de um char,converte e aponta para real e imag*/
complexo soma_complexo(complexo num1, complexo num2); /*soma*/
complexo multiplica_complexo(complexo num1, complexo num2); /*multiplica dois complexos*/
void escreve_complexo(complexo num, FILE* output); /*Escreve um complexo na forma a+bi*/
#endif // COMPLEX_H_INCLUDED
