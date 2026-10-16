#include <stdlib.h>
#include <string.h>

char* decodeString(char* s) {
    int numStack[30];
    char* strStack[30];

    int top = -1;
    int num = 0;

    char* current = (char*)malloc(100001);
    current[0] = '\0';

    for (int i = 0; s[i] != '\0'; i++) {

        // Build the number
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }

        // Save current string when '[' appears
        else if (s[i] == '[') {
            top++;

            numStack[top] = num;

            strStack[top] = (char*)malloc(100001);
            strcpy(strStack[top], current);

            current[0] = '\0';
            num = 0;
        }

        // Repeat the string when ']' appears
        else if (s[i] == ']') {
            int repeat = numStack[top];
            char* previous = strStack[top];

            char* temp = (char*)malloc(100001);
            temp[0] = '\0';

            strcpy(temp, previous);

            for (int j = 0; j < repeat; j++) {
                strcat(temp, current);
            }

            strcpy(current, temp);

            free(temp);
            free(previous);

            top--;
        }

        // Normal character
        else {
            int len = strlen(current);
            current[len] = s[i];
            current[len + 1] = '\0';
        }
    }

    return current;
}