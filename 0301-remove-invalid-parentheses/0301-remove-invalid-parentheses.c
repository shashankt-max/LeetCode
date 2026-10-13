#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    int balance = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            balance++;
        }
        else if (s[i] == ')') {
            balance--;

            if (balance < 0)
                return false;
        }
    }

    return balance == 0;
}

int contains(char** arr, int size, char* s) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], s) == 0)
            return 1;
    }

    return 0;
}

char** removeInvalidParentheses(char* s, int* returnSize) {
    int capacity = 10000;

    char** current = malloc(capacity * sizeof(char*));
    char** next = malloc(capacity * sizeof(char*));
    char** answer = malloc(capacity * sizeof(char*));

    int currentSize = 1;
    int nextSize = 0;
    int answerSize = 0;

    current[0] = malloc(strlen(s) + 1);
    strcpy(current[0], s);

    while (1) {
        bool found = false;

        for (int i = 0; i < currentSize; i++) {
            if (isValid(current[i])) {
                if (!contains(answer, answerSize, current[i])) {
                    answer[answerSize] = malloc(strlen(current[i]) + 1);
                    strcpy(answer[answerSize], current[i]);
                    answerSize++;
                }

                found = true;
            }
        }

        // We found valid strings at this level,
        // so they use the minimum number of removals.
        if (found)
            break;

        nextSize = 0;

        for (int i = 0; i < currentSize; i++) {
            int len = strlen(current[i]);

            for (int j = 0; j < len; j++) {

                // Avoid removing the same consecutive parenthesis
                // multiple times.
                if (j > 0 &&
                    current[i][j] == current[i][j - 1])
                    continue;

                if (current[i][j] != '(' &&
                    current[i][j] != ')')
                    continue;

                char* temp = malloc(len);

                int pos = 0;

                for (int k = 0; k < len; k++) {
                    if (k != j)
                        temp[pos++] = current[i][k];
                }

                temp[pos] = '\0';

                if (!contains(next, nextSize, temp)) {
                    next[nextSize++] = temp;
                }
                else {
                    free(temp);
                }
            }
        }

        for (int i = 0; i < currentSize; i++)
            free(current[i]);

        char** swap = current;
        current = next;
        next = swap;

        currentSize = nextSize;
    }

    for (int i = 0; i < currentSize; i++)
        free(current[i]);

    free(current);
    free(next);

    *returnSize = answerSize;

    return answer;
}