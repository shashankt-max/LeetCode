#include <stdlib.h>
#include <string.h>

char* removeOuterParentheses(char* s) {
    int n = strlen(s);

    char* result = (char*)malloc((n + 1) * sizeof(char));
    int index = 0;
    int depth = 0;

    for (int i = 0; i < n; i++) {

        if (s[i] == '(') {
            // Only add '(' if it is not the outermost one
            if (depth > 0)
                result[index++] = s[i];

            depth++;
        }
        else {
            depth--;

            // Only add ')' if it is not the outermost one
            if (depth > 0)
                result[index++] = s[i];
        }
    }

    result[index] = '\0';

    return result;
}