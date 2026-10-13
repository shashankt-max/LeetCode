int rob(int* nums, int numsSize) {
    int prev2 = 0;
    int prev1 = 0;

    for (int i = 0; i < numsSize; i++) {
        int current = prev1;

        if (prev2 + nums[i] > current) {
            current = prev2 + nums[i];
        }

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}