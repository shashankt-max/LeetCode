#include <stdbool.h>

typedef struct {
    int r, c, d;
} Node;

int nearestExit(char** maze,
                int mazeSize,
                int* mazeColSize,
                int* entrance,
                int entranceSize) {

    int m = mazeSize;
    int n = mazeColSize[0];

    bool visited[100][100] = {false};

    Node q[10000];
    int front = 0, rear = 0;

    q[rear++] = (Node){entrance[0], entrance[1], 0};
    visited[entrance[0]][entrance[1]] = true;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (front < rear) {
        Node cur = q[front++];

        for (int k = 0; k < 4; k++) {
            int nr = cur.r + dr[k];
            int nc = cur.c + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (visited[nr][nc] || maze[nr][nc] == '+')
                continue;

            if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1)
                return cur.d + 1;

            visited[nr][nc] = true;
            q[rear++] = (Node){nr, nc, cur.d + 1};
        }
    }

    return -1;
}