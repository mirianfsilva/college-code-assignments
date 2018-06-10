#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

int pagerep_fifo(int p,int qpage); // página a ser substituída
void pagefault_fifo(int p, int qpage); // Falta de página
int findpage_fifo(int p, int qpage); // Procura elemento no vetor


#endif // FIFO_H_INCLUDED
