#include <string.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Check if str1 + str2 == str2 + str1
    char *s1 = (char *)malloc(len1 + len2 + 1);
    char *s2 = (char *)malloc(len1 + len2 + 1);

    strcpy(s1, str1);
    strcat(s1, str2);

    strcpy(s2, str2);
    strcat(s2, str1);

    if (strcmp(s1, s2) != 0) {
        free(s1);
        free(s2);

        char *ans = (char *)malloc(1);
        ans[0] = '\0';
        return ans;
    }

    free(s1);
    free(s2);

    int g = gcd(len1, len2);

    char *ans = (char *)malloc(g + 1);
    strncpy(ans, str1, g);
    ans[g] = '\0';

    return ans;
}