#include <stdlib.h>

char* maxSumOfSquares(int num, int sum) {
    if (sum > 9 * num || sum < 1) {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char *result = malloc((num + 1) * sizeof(char));
    int remaining = sum;

    for (int i = 0; i < num; i++) {
        int digit = remaining < 9 ? remaining : 9;
        result[i] = '0' + digit;
        remaining -= digit;
    }

    result[num] = '\0';
    return result;
}