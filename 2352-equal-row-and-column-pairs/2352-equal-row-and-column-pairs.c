int equalPairs(int** grid, int gridSize, int* gridColSize){
    int n = gridSize;
    int count = 0;
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            bool match = true;
            for (int k = 0; k < n; k++) {
                if (grid[r][k] != grid[k][c]) {
                    match = false;
                    break;
                }
            }
            if (match) count++;
        }
    }
    
    return count;
}