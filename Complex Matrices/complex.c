#include "complex.h"

/* Função que cria e inicializa um novo complexo na forma a+bi */
complexo inicializar_complexo (double real, double imaginario) {
  complexo temp; // = (complexo) malloc (sizeof (complexo));
  temp.real = real;
  temp.imaginario = imaginario;
  return temp;
}

/*Ler os números complexos na forma de um char,converte e aponta para real e imag*/
complexo ler_complexo(char *str) {
  double real, imag;
	int i;

  real = atof(str); /*Parte real*/
  for (i=1; i<(int)strlen(str); i++) {
    if(str[i] == '+' || str[i] == '-') {
      imag = atof(str+i); /*Parte Imaginária*/
      break;
    }
  }
  return inicializar_complexo(real,imag);
}

/* Função: soma de números complexos */
complexo soma_complexo(complexo num1, complexo num2) {
  complexo tempsoma; // = (complexo) malloc (sizeof (complexo));
  tempsoma.real = num1.real + num2.real;
  tempsoma.imaginario = num1.imaginario + num2.imaginario;
  return tempsoma;
}

/* Função multiplicação de números complexos */
complexo multiplica_complexo(complexo num1, complexo num2) {
  complexo tempmult; // = (complexo) malloc (sizeof (complexo));
  tempmult.real = num1.real * num2.real - num1.imaginario * num2.imaginario;
  tempmult.imaginario = num1.real * num2.imaginario + num1.imaginario * num2.real;
  return tempmult;
}

/*Função que escreve um número complexo na forma a+bi */
void escreve_complexo(complexo num, FILE *output) {
  fprintf(output,"%g+ %gi ", num.real, num.imaginario);
}
