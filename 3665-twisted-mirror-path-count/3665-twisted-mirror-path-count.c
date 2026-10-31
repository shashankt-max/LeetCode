#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int m, n;
int **g;
int memo[501][501][2];

int resolve(int i, int j, int dir) {
    if (i >= m || j >= n)
        return -1;

    if (g[i][j] == 0)
        return i * n + j;

    if (memo[i][j][dir] != -2)
        return memo[i][j][dir];

    int ans;

    if (dir == 0)
        ans = resolve(i + 1, j, 1);
    else
        ans = resolve(i, j + 1, 0);

    return memo[i][j][dir] = ans;
}

int uniquePaths(int** grid, int gridSize, int* gridColSize) {
    m = gridSize;
    n = gridColSize[0];
    g = grid;

    memset(memo, 0xff, sizeof(memo));

    // -2 means not calculated
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            memo[i][j][0] = -2;
            memo[i][j][1] = -2;
        }
    }

    int dp[501][501] = {0};

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (g[i][j] == 1 || dp[i][j] == 0)
                continue;

            long long ways = dp[i][j];

            // Try moving right
            int r = resolve(i, j + 1, 0);

            if (r != -1) {
                int x = r / n;
                int y = r % n;

                dp[x][y] = (dp[x][y] + ways) % MOD;
            }

            // Try moving down
            int d = resolve(i + 1, j, 1);

            if (d != -1) {
                int x = d / n;
                int y = d % n;

                dp[x][y] = (dp[x][y] + ways) % MOD;
            }
        }
    }

    return dp[m - 1][n - 1];
}