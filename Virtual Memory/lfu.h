#ifndef LFU_H_INCLUDED
#define LFU_H_INCLUDED

int longestop_lfu(int qpage);
int pagerep_lfu(int p,int qpage);
void pagefault_lfu(int p, int qpage);
int findpage_lfu(int p, int qpage);
int loc_espacial(int p,int qpage);

#endif // LFU_H_INCLUDED
