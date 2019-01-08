#include <stdlib.h>
#include <stdio.h>

int mdc(int a, int b) {
  if(a<0) a = -a;
  if(b<0) b = -b;

  if(b == 0)
    return a;
  else
    return mdc(b, a%b);
}

int main(){
    int a,p,k;
    float inverso;

    system("color 1F");

    printf(" ***CALCULANDO O INVERSO*** ");
    /*Recebendo o valor de A */
    printf("Digite um valor: \n");
    scanf("%d",&a);

    /*Recebendo o valor de P */
    printf("Digite outro valor: \n");
    scanf("%d",&p);

    inverso = k * p+a;

    printf("O inverso de %d mod %d = %f\n",a,p,inverso);
    
return 0;
}
