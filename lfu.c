#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//LFU (Last Frequently Use)

int full_lfu=0;//Verifica se todos os frames estão preenchidos
int longestop_lfu(int qpage){//entrada pagina referenciada, qntd de páginas, acessos
	int min,repp,i,ctr[qpage];
	min = 0;
  for(i=0; i< qpage; i++) // a página com menos frequencia eh selecionada para sair
		if(ctr[min]>ctr[i])
			min=i;
			repp = min;
			return repp;
}

int pagerep_lfu(int p,int qpage) { // page - replaced (repõe página)
  int temp = 0,repp = 0; // página q derevá ser substituida

	repp = longestop_lfu(qpage); // página q irá sair selecionada. Função para auxiliar na reposição.
  int *frame;
  frame = malloc(qpage*(sizeof(int)));
  int *ctr;
  ctr = malloc(qpage*(sizeof(int)));

  temp = frame[repp];
  frame[repp] = p;
  ctr[repp] = 1;//Uma nova página será trazida,contador é definido como 1

  return temp;   //retorna página q será retirada
  free(frame);
  free(ctr);
}

void pagefault_lfu(int p, int qpage) {
	qpage= 0;
  int *frame, ctr[qpage];

  frame = malloc(qpage*(sizeof(int)));
  if(full_lfu != qpage){
    ctr[full_lfu]++;
		frame[full_lfu++] = p;//Até que todos os frames estejam cheios, não há pedido de substituição de página
  }else{ pagerep_lfu(p,qpage);}
}

int findpage_lfu(int p, int qpage) { //Pesquisar e retornar o flag que indica se a página já está presente no frame ou não
  int frame[qpage], ctr[qpage];
  int i,flag=0;

  if(full_lfu!=0) {
    for(i=0; i<full_lfu; i++)
      if(p == frame[i]) {
        flag=1;
        ctr[i]++; // sempre que é feita uma referência ao contador é incrementado
        break;
      }
  }
  return flag;
}

int loc_espacial(int p,int qpage){
	if (findpage_lfu(p,qpage))
		return 0;
	else if (findpage_lfu(p,qpage) != 1)
		return -1;
	else
		return longestop_lfu(qpage);
}
