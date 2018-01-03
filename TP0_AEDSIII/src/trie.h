#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define ALPHABET_SIZE 26
#define WORDS_SIZE 20
#define TEXT_SIZE 10^6
#define DICT_SIZE 10^5

typedef struct TrieNode{
    bool end;
    int count; // This will store the starting indices of the word occurring in the given text.
    struct TrieNode *child[ALPHABET_SIZE];
} TrieNode;

/// Code - Functions ///

TrieNode *initializer(void);
int search_word(TrieNode *head, char *word);
void add_word(TrieNode *head, char *word);
void free_trie(TrieNode* current);



#endif // TRIE_H_INCLUDED
