#include <string.h>
#include <stdlib.h>

char* reverseWords(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc(len + 1);
    int k = 0;

    int i = len - 1;

    while (i >= 0) {
        // Skip spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        if (i < 0) {
            break;
        }

        int end = i;

        // Find start of word
        while (i >= 0 && s[i] != ' ') {
            i--;
        }

        int start = i + 1;

        // Add a space before next word (except first)
        if (k > 0) {
            result[k++] = ' ';
        }

        // Copy word
        for (int j = start; j <= end; j++) {
            result[k++] = s[j];
        }
    }

    result[k] = '\0';
    return result;
}