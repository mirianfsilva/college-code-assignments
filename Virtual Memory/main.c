#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fifo.h"
#include "lfu.h"
#include "lru.h"
#include "mfu.h"

int convert_num_frame(int p,int size_page) { // converte numero de entrada no identificador da página
  return (p = (floor(p/size_page))*size_page);
}

int main(int argc, char *argv[]) {

  int i,j,n,inst,qpage,psize,msize;//n = acessos - Input txt
  int *aux, count_lru,count_lfu, count_fifo,count_mfu;

  FILE *fin = fopen(argv[1], "r"); 
  FILE *fout = fopen(argv[2], "w"); 

  if(fin == NULL || fout == NULL) {
    printf("Erro ao abrir o(s) arquivo(s).");
    return 0;
  }

  fscanf(fin, "%d\n",&inst); 
  for(j = 0; j <inst ; j++) {
    fscanf(fin,"%d %d %d\n",&msize,&psize,&n);
    qpage =(msize/psize); 

    aux = (int*) malloc(msize*sizeof(int));

    for (i=0; i < n; i++) {
      fscanf(fin,"%d",&aux[i]);
      aux[i] = convert_num_frame(aux[i],psize);
    }
		count_fifo = 0;
		count_lfu = 0;
		count_lru = 0;
		count_mfu = 0;

		for(i=0; i<n; i++){
			if(findpage_fifo(aux[i],qpage)!=1){ // Start FIFO
				pagefault_fifo(aux[i],qpage);
				count_fifo++;
			}
			if(findpage_lfu(aux[i],qpage)!=1){ // Start LFU
				pagefault_lfu(aux[i],qpage);
				count_lfu++;
			}
			if(findpage_lru(aux[i],qpage,n)!=1){ // Start LRU
				pagefault_lru(aux[i],qpage,n);
				count_lru++;
			}
			if(findpage_mfu(aux[i],qpage)!=1){ // Start MFU
				pagefault_mfu(aux[i],qpage);
				count_mfu++;
			}
		}
		fprintf(fout,"%d %d %d %d",count_fifo,count_lru,count_lfu,count_mfu);
		fprintf(fout,"%d\n", loc_espacial(aux[i],qpage));
		fprintf(fout,"%d\n", loc_temporal(aux[i], qpage));
	}
	
  fclose(fin);
  fclose(fout);
  free(aux);
  return 0;
}
