#include <string.h>
int scoreOfParentheses(char* s) {
    int stack[50];
    int top = 0;
    stack[0] = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            stack[++top] = 0;
        }
        else {
            int value = stack[top--];

            if (value == 0)
                value = 1;
            else
                value *= 2;

            stack[top] += value;
        }
    }
    return stack[0];
}