#ifndef LRU_H_INCLUDED
#define LRU_H_INCLUDED

int lrstacktop_lru(int p, int qpage,int n);
int pagerep_lru(int p,int qpage,int n);
void pagefault_lru(int p, int qpage,int n);
int findpage_lru(int p, int qpage,int n);
int loc_espacial(int p,int qpage, int n);

#endif // LRU_H_INCLUDED
