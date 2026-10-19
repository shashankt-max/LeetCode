#include <stdlib.h>

int* targetIndices(int* nums, int numsSize, int target,
                   int* returnSize) {
    int less = 0, equal = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < target)
            less++;
        else if (nums[i] == target)
            equal++;
    }

    *returnSize = equal;
    int* result = malloc(equal * sizeof(int));

    for (int i = 0; i < equal; i++) {
        result[i] = less + i;
    }

    return result;
}