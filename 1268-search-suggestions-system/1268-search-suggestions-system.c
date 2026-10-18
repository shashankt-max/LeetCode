#include <stdlib.h>
#include <string.h>

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

char*** suggestedProducts(char** products, int productsSize,
                          char* searchWord, int* returnSize,
                          int** returnColumnSizes) {
    qsort(products, productsSize, sizeof(char *), compareStrings);

    int len = strlen(searchWord);

    char ***result = malloc(len * sizeof(char **));
    *returnColumnSizes = malloc(len * sizeof(int));
    *returnSize = len;

    for (int i = 0; i < len; i++) {
        result[i] = malloc(3 * sizeof(char *));
        (*returnColumnSizes)[i] = 0;

        for (int j = 0; j < productsSize; j++) {
            if (strncmp(products[j], searchWord, i + 1) == 0) {
                result[i][(*returnColumnSizes)[i]++] = products[j];

                if ((*returnColumnSizes)[i] == 3)
                    break;
            }
        }
    }

    return result;
}