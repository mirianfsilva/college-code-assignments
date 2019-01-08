#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
// Euler's totient
 
/*Função que testa se o numero digitado é primo */
bool ehprimo(int num) {
    if (num <= 1){
        return false; // zero e um nao sao primos
    }
    int i;
    for (i=2; i*i<=num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int mdc(int a,int b){
    if (b!=0){
        return mdc(b,a%b);
    }
    else
        return 1;
}

int main(){
    int k,i,q,p, PhideEuler;
    int primo = 1;

    printf("Digite um valor: ");
    scanf("%d",&k);
    if (k<=0){
        printf("Valor inválido");
        exit (0);
    }

    if (ehprimo(k)== true){
        PhideEuler = k - 1;
        printf("Phi de Euller = %d\n",PhideEuler);
    }
    else
        if (mdc(p,q) == 1){
            if (ehprimo(p) == true && ehprimo(q)== true){
                if (k = p*q){
                    PhideEuler = (p-1)*(q-1);
                    printf("Phi de Euler = %d",PhideEuler);
                }
            }
        }

system ("pause");
return 0;
}
