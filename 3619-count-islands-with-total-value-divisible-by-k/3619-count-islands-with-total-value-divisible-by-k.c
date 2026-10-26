
long long dfs(int** grid, int m, int n, int r, int c) {
    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
        return 0;

    long long sum = grid[r][c];
    grid[r][c] = 0;

    sum += dfs(grid, m, n, r - 1, c);
    sum += dfs(grid, m, n, r + 1, c);
    sum += dfs(grid, m, n, r, c - 1);
    sum += dfs(grid, m, n, r, c + 1);

    return sum;
}

int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int count = 0;
    int n = gridColSize[0];

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                long long sum = dfs(grid, gridSize, n, i, j);
                if (sum % k == 0)
                    count++;
            }
        }
    }

    return count;
}
