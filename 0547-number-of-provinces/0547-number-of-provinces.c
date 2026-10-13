#include <stdbool.h>

void dfs(int city, int** isConnected, int n, bool* visited) {
    visited[city] = true;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(i, isConnected, n, visited);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize,
                  int* isConnectedColSize) {
    
    int n = isConnectedSize;
    bool visited[200] = {false};
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            provinces++;
            dfs(i, isConnected, n, visited);
        }
    }

    return provinces;
}