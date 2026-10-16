int minDistance(char* word1, char* word2) {
    int m = 0, n = 0;

    while (word1[m] != '\0') m++;
    while (word2[n] != '\0') n++;

    int dp[501][501] = {0};

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int insert = dp[i][j - 1];
                int delete = dp[i - 1][j];
                int replace = dp[i - 1][j - 1];

                int minimum = insert < delete ? insert : delete;
                if (replace < minimum)
                    minimum = replace;

                dp[i][j] = minimum + 1;
            }
        }
    }

    return dp[m][n];
}