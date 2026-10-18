#define MOD 1000000007LL

long long comb[1001][1001];

long long solve(int *nums, int size) {
    if (size <= 2) return 1;

    int left[1000], right[1000];
    int l = 0, r = 0;
    int root = nums[0];

    for (int i = 1; i < size; i++) {
        if (nums[i] < root)
            left[l++] = nums[i];
        else
            right[r++] = nums[i];
    }

    long long ways = comb[l + r][l];
    ways = (ways * solve(left, l)) % MOD;
    ways = (ways * solve(right, r)) % MOD;

    return ways;
}

int numOfWays(int* nums, int numsSize) {
    for (int i = 0; i <= numsSize; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1]
                        + comb[i - 1][j]) % MOD;
        }
    }

    return (int)((solve(nums, numsSize) - 1 + MOD) % MOD);
}