int longestCommonSubsequence(char* text1, char* text2) {
    int m = 0, n = 0;

    while (text1[m] != '\0') m++;
    while (text2[n] != '\0') n++;

    int dp[1001][1001] = {0};

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1])
                         ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}