#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize,
                       int* returnSize) {
    int *answer = calloc(temperaturesSize, sizeof(int));
    int *stack = malloc(temperaturesSize * sizeof(int));
    int top = -1;

    *returnSize = temperaturesSize;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 &&
               temperatures[i] > temperatures[stack[top]]) {
            int prev = stack[top--];
            answer[prev] = i - prev;
        }

        stack[++top] = i;
    }

    free(stack);
    return answer;
}