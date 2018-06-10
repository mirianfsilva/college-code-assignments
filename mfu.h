#ifndef MFU_H_INCLUDED
#define MFU_H_INCLUDED


int longestop_mfu(int qpage);/*Função para descobrir a página mais recentemente utilizados através de seus valores de contagem*/
int pagerep_mfu(int p, int qpage);
void pagefault_mfu(int p, int qpage);
int findpage_mfu(int p, int qpage);

#endif // MFU_H_INCLUDED
