#include <stdlib.h>

int result[512][9];
int resultCount;
int path[9];

void backtrack(int start, int k, int n, int depth) {
    if (depth == k) {
        if (n == 0) {
            for (int i = 0; i < k; i++) {
                result[resultCount][i] = path[i];
            }
            resultCount++;
        }
        return;
    }

    for (int i = start; i <= 9; i++) {
        if (i > n) {
            break;
        }

        path[depth] = i;
        backtrack(i + 1, k, n - i, depth + 1);
    }
}

int** combinationSum3(int k, int n, int* returnSize,
                      int** returnColumnSizes) {
    resultCount = 0;

    backtrack(1, k, n, 0);

    int **answer = malloc(resultCount * sizeof(int *));
    *returnColumnSizes = malloc(resultCount * sizeof(int));
    *returnSize = resultCount;

    for (int i = 0; i < resultCount; i++) {
        answer[i] = malloc(k * sizeof(int));

        for (int j = 0; j < k; j++) {
            answer[i][j] = result[i][j];
        }

        (*returnColumnSizes)[i] = k;
    }

    return answer;
}