#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXV 50

char vars[MAXV][6];
int varCount = 0;

int getId(char* s) {
    for (int i = 0; i < varCount; i++) {
        if (strcmp(vars[i], s) == 0)
            return i;
    }

    strcpy(vars[varCount], s);
    return varCount++;
}

double dfs(int cur, int target, double graph[MAXV][MAXV], bool* visited) {
    if (cur == target)
        return 1.0;

    visited[cur] = true;

    for (int i = 0; i < varCount; i++) {
        if (graph[cur][i] > 0 && !visited[i]) {
            double res = dfs(i, target, graph, visited);

            if (res != -1.0)
                return graph[cur][i] * res;
        }
    }

    return -1.0;
}

double* calcEquation(char*** equations, int equationsSize,
                     int* equationsColSize, double* values,
                     int valuesSize, char*** queries,
                     int queriesSize, int* queriesColSize,
                     int* returnSize) {

    varCount = 0;

    double graph[MAXV][MAXV] = {0};

    // Build graph
    for (int i = 0; i < equationsSize; i++) {
        int u = getId(equations[i][0]);
        int v = getId(equations[i][1]);

        graph[u][v] = values[i];
        graph[v][u] = 1.0 / values[i];
    }

    double* ans = (double*)malloc(sizeof(double) * queriesSize);

    for (int i = 0; i < queriesSize; i++) {

        int src = -1, dst = -1;

        for (int j = 0; j < varCount; j++) {
            if (strcmp(vars[j], queries[i][0]) == 0)
                src = j;

            if (strcmp(vars[j], queries[i][1]) == 0)
                dst = j;
        }

        if (src == -1 || dst == -1) {
            ans[i] = -1.0;
            continue;
        }

        bool visited[MAXV] = {false};
        ans[i] = dfs(src, dst, graph, visited);
    }

    *returnSize = queriesSize;
    return ans;
}