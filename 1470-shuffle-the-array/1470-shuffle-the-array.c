#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    *returnSize = numsSize;

    int* result = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < n; i++) {
        result[2 * i] = nums[i];
        result[2 * i + 1] = nums[i + n];
    }

    return result;
}