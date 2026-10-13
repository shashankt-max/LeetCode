#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

long long maxAlternatingSum(int* nums, int numsSize) {
    long long *sq = malloc(numsSize * sizeof(long long));

    for (int i = 0; i < numsSize; i++) {
        sq[i] = (long long)nums[i] * nums[i];
    }

    // Sort squared values in ascending order
    qsort(sq, numsSize, sizeof(long long),
          (int (*)(const void *, const void *))compare);

    long long score = 0;
    int negatives = numsSize / 2;

    for (int i = 0; i < numsSize; i++) {
        if (i < negatives)
            score -= sq[i];
        else
            score += sq[i];
    }

    free(sq);
    return score;
}