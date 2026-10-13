int diagonalSum(int** mat, int matSize, int* matColSize) {
    int sum = 0;
    int n = matSize;

    for (int i = 0; i < n; i++) {
        // Primary diagonal
        sum += mat[i][i];

        // Secondary diagonal, avoiding double-counting the center
        if (i != n - 1 - i) {
            sum += mat[i][n - 1 - i];
        }
    }

    return sum;
}