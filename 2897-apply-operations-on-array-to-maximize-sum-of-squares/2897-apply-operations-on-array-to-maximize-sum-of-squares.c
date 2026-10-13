#define MOD 1000000007LL

long long maxSum(int* nums, int numsSize, int k) {
    long long bitCount[31] = {0};

    for (int i = 0; i < numsSize; i++) {
        for (int b = 0; b < 31; b++) {
            if ((nums[i] >> b) & 1)
                bitCount[b]++;
        }
    }

    long long answer = 0;

    for (int i = 0; i < k; i++) {
        long long value = 0;

        for (int b = 0; b < 31; b++) {
            if (bitCount[b] > 0) {
                value |= (1LL << b);
                bitCount[b]--;
            }
        }

        answer = (answer + value * value) % MOD;
    }

    return answer;
}