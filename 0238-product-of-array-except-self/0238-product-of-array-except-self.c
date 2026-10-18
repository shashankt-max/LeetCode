#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(numsSize * sizeof(int));

    *returnSize = numsSize;

    // Store prefix products
    int prefix = 1;

    for (int i = 0; i < numsSize; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    // Multiply by suffix products
    int suffix = 1;

    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}