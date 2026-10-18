#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize * 2;

    int* ans = (int*)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }

    return ans;
}