#include <string.h>
#include <stdlib.h>

char* mergeAlternately(char* word1, char* word2) {
    int n = strlen(word1);
    int m = strlen(word2);

    char *result = (char *)malloc(n + m + 1);

    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }

    while (i < n) {
        result[k++] = word1[i++];
    }

    while (j < m) {
        result[k++] = word2[j++];
    }

    result[k] = '\0';
    return result;
}