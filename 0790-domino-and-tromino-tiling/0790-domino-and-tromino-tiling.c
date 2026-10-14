#define MOD 1000000007

int numTilings(int n) {
    if (n <= 2) {
        return n;
    }

    long long dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for (int i = 4; i <= n; i++) {
        dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
    }

    return (int)dp[n];
}