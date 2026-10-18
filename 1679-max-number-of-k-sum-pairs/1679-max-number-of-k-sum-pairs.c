#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxOperations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    int left = 0;
    int right = numsSize - 1;
    int operations = 0;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == k) {
            operations++;
            left++;
            right--;
        }
        else if (sum < k) {
            left++;
        }
        else {
            right--;
        }
    }

    return operations;
}