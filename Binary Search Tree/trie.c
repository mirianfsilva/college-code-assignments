#include "trie.h"

/// Code - Functions ///


TrieNode *initializer(void){
/*
 *   Initialize the heades with the following function;
 */
    //TrieNode *head = NULL;
    TrieNode *head = (TrieNode*)malloc(sizeof(TrieNode));
    head->count = 0;
    head->end = false;

    for(int i = 0; i < ALPHABET_SIZE; i++){
        head->child[i] = NULL;
    }
    return head;
}

int search_word(TrieNode *head, char *word){
    int len = strlen(word);

    for(int i = 0; i < len;i++){
        if((head->child[word[i] - 97]) == NULL){
            return false;
        }
        head = head->child[word[i] - 97];
    }
    /*
    *head->end;
    *if(head->count!=0)
    *    return true;
    * else
    *   return false;
    */
    return head->count;
}

void add_word(TrieNode *head, char *word){
/*
 *   The add_word function consists of three parameters. An insert operation,
 *   there a few cases:
 *   The word to be inserted does not exist.
 *   The word to be inserted already exists in the tree.
 *   The word to be inserted does not exists, but as the suffix of a word.
 *   add function - Complexity O(str_length)
 */
    if(NULL == head){
        return;
    }
    //int count = 0;
    int len = strlen(word);
    TrieNode *temp = head;

    for(int i = 0; i < len; i++){
        /* If the child is pointing to NULL, initializer new node;
        *  [word[i] - '97'] represents the next character of the string.
        *  97 = ASCII Table (a);
        */

        if(temp->child[word[i] - 97] == NULL){
            temp->child[word[i] - 97] = initializer();
        }
        temp = temp->child[word[i] - 97];
    }
    //count++;
    temp->end = true;
    temp->count++; // = count;
}

void free_trie(TrieNode* current){
/*
 *  free memory
 */
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if(current->child[i] != NULL){
            free_trie(current->child[i]);
        }
    }
    free(current);
}
