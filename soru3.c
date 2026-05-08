#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, const char* key) {
    TrieNode* p = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!p->children[index])
            p->children[index] = createNode();
        p = p->children[index];
    }
    p->isEndOfWord = true;
}

bool search(TrieNode* root, const char* key) {
    TrieNode* p = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!p->children[index])
            return false;
        p = p->children[index];
    }
    return p->isEndOfWord;
}

int main() {
    TrieNode* root = createNode();
    insert(root, "hello");
    insert(root, "world");

    printf("hello bulundu mu? %s\n", search(root, "hello") ? "Evet" : "Hayır");
    printf("hi bulundu mu? %s\n", search(root, "hi") ? "Evet" : "Hayır");

    return 0;
}
