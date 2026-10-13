typedef struct {
    int row;
    int col;
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    Node queue[100];
    int front = 0, rear = 0;

    int fresh = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j};
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0)
        return 0;

    int minutes = 0;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    while (front < rear && fresh > 0) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            Node curr = queue[front++];

            for (int d = 0; d < 4; d++) {
                int nr = curr.row + dirs[d][0];
                int nc = curr.col + dirs[d][1];

                if (nr >= 0 && nr < gridSize &&
                    nc >= 0 && nc < gridColSize[0] &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 2;
                    fresh--;

                    queue[rear++] = (Node){nr, nc};
                }
            }
        }

        minutes++;
    }

    return fresh == 0 ? minutes : -1;
}