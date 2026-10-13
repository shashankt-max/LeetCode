#include <stdlib.h>

int minReorder(int n, int** connections, int connectionsSize,
               int* connectionsColSize) {

    int** graph = (int**)malloc(n * sizeof(int*));
    int* degree = (int*)calloc(n, sizeof(int));

    // Count neighbors
    for (int i = 0; i < connectionsSize; i++) {
        int a = connections[i][0];
        int b = connections[i][1];

        degree[a]++;
        degree[b]++;
    }

    // Create graph
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    int* index = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        int a = connections[i][0];
        int b = connections[i][1];

        // Original road: a -> b
        // 1 means this road needs to be reversed
        graph[a][index[a]++] = b * 2 + 1;

        // For traversal: b -> a
        // 0 means this direction already points toward 0
        graph[b][index[b]++] = a * 2;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* queue = (int*)malloc(n * sizeof(int));

    int front = 0;
    int rear = 0;
    int changes = 0;

    queue[rear++] = 0;
    visited[0] = 1;

    while (front < rear) {
        int current = queue[front++];

        for (int i = 0; i < degree[current]; i++) {
            int edge = graph[current][i];

            int neighbor = edge / 2;
            int direction = edge % 2;

            if (visited[neighbor])
                continue;

            visited[neighbor] = 1;
            queue[rear++] = neighbor;

            // Original road points away from city 0
            if (direction == 1)
                changes++;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++)
        free(graph[i]);

    free(graph);
    free(degree);
    free(index);
    free(visited);
    free(queue);

    return changes;
}