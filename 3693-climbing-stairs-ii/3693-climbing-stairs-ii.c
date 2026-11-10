int climbStairs(int n, int* costs, int costsSize) {
    int dp[100001];

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = 1000000000;

        for (int j = 1; j <= 3; j++) {
            if (i - j >= 0) {
                int current = dp[i - j] + costs[i - 1] + j * j;

                if (current < dp[i]) {
                    dp[i] = current;
                }
            }
        }
    }

    return dp[n];
}