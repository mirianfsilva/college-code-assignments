#include <stdio.h>
#include <stdlib.h>
#include "lru.h"
//LRU (Last Recently used)

int full_lru=0; 
/* função para remoção do elemento referenciado a partir da pilha mantido na parte superior.
reorganiza todos os elementos.*/
int lrstacktop_lru(int p, int qpage,int n){ //entrada pagina referenciada, qntd de páginas, acessos
	n = 0;
	int temp=0,i,stk[qpage];

  for(i=0; i<n; i++) // qntdade de acessos
		if(stk[i] == p)
		break;
		temp = stk[i];//armazena valor referenciado em temp

  while(i!=qpage-1){//move os elementos pq o topo está vazio
		stk[i]=stk[i+1];
    i++;
  }
  stk[i] = temp;//elemento do topo, armazenado em temp
  return temp;
}

int pagerep_lru(int p,int qpage,int n) { // repõe página
  int temp,repp = 0; // página q derevá ser substituida

  int *frame;
  frame = malloc(qpage*(sizeof(int)));

  int *stk;
  stk = malloc(qpage*(sizeof(int)));

  repp = stk[0]; // Sempre a página q for sair é o primeiro elemento da pilha
  temp = frame[repp];
  frame[repp] = p;
  lrstacktop_lru(repp,qpage,n);//A page trazida, é a mais recente referênciada, logo trazida para o topo

  return temp;   //retorna página q será retirada
//  free(frame);
//  free(stk);
}

void pagefault_lru(int p, int qpage,int n) {
  int *frame, *stk;
  //int frame[qpage], stk[qpage];

  frame = malloc(qpage*(sizeof(int)));
  stk = malloc(qpage*(sizeof(int)));

  if(full_lru != qpage){
    stk[full_lru] = full_lru; // primeiro da pilha é preenchida até que todas as páginas estão cheias
		frame[full_lru++] = p;//Até que todos os frames estejam cheios, não há pedido de substituição de página
  }else{
  	pagerep_lru(p,qpage,n);
  }
// free(frame);
// free(stk);
}

int findpage_lru(int p, int qpage,int n) { //Pesquisar e retornar o flag que indica se a página já está presente no frame ou não
  int frame[qpage];
  int i,flag=0;

  if(full_lru!=0) {
    for(i=0; i<full_lru; i++)
      if(p == frame[i]) {
        flag=1;
        lrstacktop_lru(i,qpage,n); //Sempre que se faz referência, mas erro de página não ocorre, a página referenciada é movida para o topo
        break;
      }
  }
  return flag;
}

int loc_temporal(int p,int qpage, int n){
  int stk[qpage],i;
  
  if (findpage_lru(p,qpage,n) == 1) {
    lrstacktop_lru(int p, int qpage,int n);
  }
}
