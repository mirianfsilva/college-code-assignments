#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#define DEBUGx

int main(int argc, char **argv){
    int words_d; // number of words in the dictionaty, to be checked in trie tree
    int words_t; // number of words in the text, to be inserted in trie tree
    TrieNode *trie_t = initializer();

    scanf("%d",&words_d);
    char dictionary[words_d][WORDS_SIZE];
    for (int i = 0; i < words_d; i++){
        scanf("%s",dictionary[i]);
    }

#ifndef DEBUGx
    for (int i = 0; i < words_d; i++){
        printf("%s\t",dictionary[i]);
    }
#endif // DEBUGx

    scanf("%d",&words_t);
    char text[words_t][WORDS_SIZE];
    for (int j = 0; j < words_t; j++){
        scanf("%s",text[j]);
        add_word(trie_t,text[j]);
    }

    for(int i = 0; i < words_d; i++){
        printf("%d ",search_word(trie_t,dictionary[i]));
    }

    free(dictionary);
    free_trie(trie_t);

    return 0;
}

