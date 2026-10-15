long long sumCounts(int* nums, int numsSize) {
    long long total = 0;

    for (int i = 0; i < numsSize; i++) {
        int seen[101] = {0};
        int distinct = 0;

        for (int j = i; j < numsSize; j++) {
            if (!seen[nums[j]]) {
                seen[nums[j]] = 1;
                distinct++;
            }

            total += (long long)distinct * distinct;
        }
    }

    return total;
}