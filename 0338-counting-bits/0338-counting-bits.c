#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    int *ans = malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;

    ans[0] = 0;

    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i / 2] + (i % 2);
    }

    return ans;
}