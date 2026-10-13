#include <stdlib.h>
#include <string.h>

char *mapping[] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char *digits, int index, char *path,
               char **result, int *count) {
    if (digits[index] == '\0') {
        path[index] = '\0';
        result[*count] = malloc((index + 1) * sizeof(char));
        strcpy(result[*count], path);
        (*count)++;
        return;
    }

    char *letters = mapping[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        path[index] = letters[i];
        backtrack(digits, index + 1, path, result, count);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    *returnSize = 0;

    if (digits == NULL || digits[0] == '\0') {
        return NULL;
    }

    int n = strlen(digits);
    int capacity = 1;

    for (int i = 0; i < n; i++) {
        capacity *= strlen(mapping[digits[i] - '0']);
    }

    char **result = malloc(capacity * sizeof(char *));
    char *path = malloc((n + 1) * sizeof(char));

    backtrack(digits, 0, path, result, returnSize);

    free(path);
    return result;
}