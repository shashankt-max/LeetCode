#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;

    return (x > y) - (x < y);
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int median = nums[numsSize / 2];
    long long moves = 0;

    for (int i = 0; i < numsSize; i++) {
        moves += llabs((long long)nums[i] - median);
    }

    return (int)moves;
}