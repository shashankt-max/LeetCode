int countServers(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int row[250] = {0};
    int col[250] = {0};

    // Count servers in each row and column
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                row[i]++;
                col[j]++;
            }
        }
    }

    int ans = 0;

    // Count servers that share a row or column
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 &&
                (row[i] > 1 || col[j] > 1)) {
                ans++;
            }
        }
    }

    return ans;
}