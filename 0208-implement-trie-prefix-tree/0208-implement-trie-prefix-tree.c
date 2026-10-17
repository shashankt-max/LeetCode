#include <stdlib.h>
#include <stdbool.h>

typedef struct Trie {
    struct Trie *children[26];
    bool isEnd;
} Trie;

Trie* trieCreate() {
    return calloc(1, sizeof(Trie));
}

void trieInsert(Trie* obj, char* word) {
    Trie *current = obj;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            current->children[index] = trieCreate();
        }

        current = current->children[index];
    }

    current->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie *current = obj;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL) {
            return false;
        }

        current = current->children[index];
    }

    return current->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie *current = obj;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (current->children[index] == NULL) {
            return false;
        }

        current = current->children[index];
    }

    return true;
}

void trieFree(Trie* obj) {
    if (obj == NULL) return;

    for (int i = 0; i < 26; i++) {
        trieFree(obj->children[i]);
    }

    free(obj);
}