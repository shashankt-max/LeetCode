#include <stdlib.h>
#include <string.h>

void generate(char** result, char* current, int n,
               int open, int close, int* count) {

    if (open == n && close == n) {
        current[open + close] = '\0';

        result[*count] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*count], current);

        (*count)++;
        return;
    }

    if (open < n) {
        current[open + close] = '(';
        generate(result, current, n, open + 1, close, count);
    }

    if (close < open) {
        current[open + close] = ')';
        generate(result, current, n, open, close + 1, count);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int maxResults = 1430;

    char** result = (char**)malloc(maxResults * sizeof(char*));
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));

    *returnSize = 0;

    generate(result, current, n, 0, 0, returnSize);

    free(current);

    return result;
}