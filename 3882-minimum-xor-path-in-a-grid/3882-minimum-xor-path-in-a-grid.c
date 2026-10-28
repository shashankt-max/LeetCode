
int minCost(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int dp[1000][1024] = {0};

    for (int i = 0; i < m; i++) {
        int left[1024] = {0};

        for (int j = 0; j < n; j++) {
            int next[1024] = {0};

            if (i == 0 && j == 0) {
                next[grid[0][0]] = 1;
            } else {
                for (int x = 0; x < 1024; x++) {
                    if (i > 0 && dp[j][x])
                        next[x ^ grid[i][j]] = 1;

                    if (left[x])
                        next[x ^ grid[i][j]] = 1;
                }
            }

            for (int x = 0; x < 1024; x++)
                left[x] = next[x];

            for (int x = 0; x < 1024; x++)
                dp[j][x] = next[x];
        }
    }

    for (int x = 0; x < 1024; x++)
        if (dp[n - 1][x])
            return x;

    return 0;
}
