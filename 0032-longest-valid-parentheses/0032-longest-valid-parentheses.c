#include <stdlib.h>

int longestValidParentheses(char* s) {
    int n = 0;
    while (s[n] != '\0') n++;

    int *stack = (int *)malloc((n + 1) * sizeof(int));
    int top = -1;
    int maxLen = 0;

    stack[++top] = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;

            if (top < 0) {
                stack[++top] = i;
            } else {
                int len = i - stack[top];
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    free(stack);
    return maxLen;
}