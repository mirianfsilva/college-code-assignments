#include <stdio.h>
#include <stdlib.h>
#include "mfu.h"

// MFU (Most Frequently Used )
int full_mfu =0;
int longestop_mfu(int qpage){
	int i,max,repp = 0;
	int ctr [qpage];

	for (i=0; i<qpage;i++){ctr[i] = 0;}

  max = 0;//Incremento do valor de contador é a mesma que a do LFU
  for(i=0; i<qpage; i++) //A página com frequência máxima é selecionada
    if(ctr[max]<ctr[i])
      max=i;
  		repp = max;
  return repp;
}

int pagerep_mfu(int p, int qpage){
  int i,temp,repp=0;
  int ctr[qpage]; //, frame[qpage];
	
	//int *ctr;
	//ctr = (int*) malloc(qpage*(sizeof(int)));
	int *frame;
	frame = malloc(qpage*(sizeof(int)));
	
	for (i=0; i<qpage;i++){ctr[i] = 0;}

  repp = longestop_mfu(qpage);
  temp = frame[repp];
  frame[repp]= p;
  ctr[repp] = 1;
  
	free(frame);
  //free(ctr);
  return temp; 
}

void pagefault_mfu(int p, int qpage){
	int ctr[qpage],i;

	int *frame;
	frame = malloc(qpage*(sizeof(int)));
	
	for (i=0; i<qpage;i++){ctr[i] = 0;}

	if(full_mfu != qpage){
		ctr[full_mfu]++;
    frame[full_mfu++] = p;
  }
  else{
  	pagerep_mfu(p,qpage);
  }
}

int findpage_mfu(int p, int qpage){
	int i, flag=0;
	int ctr[qpage], frame [qpage];
	
	for (i=0; i<qpage;i++){ ctr[i] = 0;}

  if(full_mfu != 0){
    for(i=0; i<full_mfu; i++)
      if(p == frame[i]){
      	flag=1;
        ctr[i]++;
        break;
      }
  }
  return flag;
}
