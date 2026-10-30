#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef long long ll;

typedef struct {
    int to;
    int weight;
    int next;
} Edge;

#define MAXN 50005
#define MAXE 50005
#define INF LLONG_MAX

Edge edgesList[MAXE];
int head[MAXN];
int edgeCount;

typedef struct {
    ll dist;
    int node;
    int count;
} State;

void addEdge(int u, int v, int w) {
    edgesList[edgeCount].to = v;
    edgesList[edgeCount].weight = w;
    edgesList[edgeCount].next = head[u];
    head[u] = edgeCount++;
}

int shortestPath(int n, int** edges, int edgesSize,
                 int* colsize, char* labels, int k){

    for (int i = 0; i < n; i++)
        head[i] = -1;

    edgeCount = 0;

    for (int i = 0; i < edgesSize; i++) {
        addEdge(edges[i][0], edges[i][1], edges[i][2]);
    }

    ll (*dist)[51] = malloc(n * sizeof(*dist));

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            dist[i][j] = INF;

    // Min-heap
    int capacity = 1000000;
    State *heap = malloc(capacity * sizeof(State));
    int heapSize = 0;

    // Insert starting state
    dist[0][1] = 0;
    heap[++heapSize] = (State){0, 0, 1};

    // Heap insertion
    #define PUSH(val) do { \
        int idx = ++heapSize; \
        heap[idx] = (val); \
        while (idx > 1 && heap[idx].dist < heap[idx / 2].dist) { \
            State temp = heap[idx]; \
            heap[idx] = heap[idx / 2]; \
            heap[idx / 2] = temp; \
            idx /= 2; \
        } \
    } while (0)

    // Heap removal
    #define POP() do { \
        heap[1] = heap[heapSize--]; \
        int idx = 1; \
        while (1) { \
            int smallest = idx; \
            int l = idx * 2, r = l + 1; \
            if (l <= heapSize && heap[l].dist < heap[smallest].dist) smallest = l; \
            if (r <= heapSize && heap[r].dist < heap[smallest].dist) smallest = r; \
            if (smallest == idx) break; \
            State temp = heap[idx]; \
            heap[idx] = heap[smallest]; \
            heap[smallest] = temp; \
            idx = smallest; \
        } \
    } while (0)

    while (heapSize > 0) {
        State cur = heap[1];
        POP();

        int u = cur.node;
        int cnt = cur.count;
        ll d = cur.dist;

        if (d != dist[u][cnt])
            continue;

        if (u == n - 1) {
            free(heap);
            free(dist);
            return d;
        }

        for (int e = head[u]; e != -1; e = edgesList[e].next) {
            int v = edgesList[e].to;
            int w = edgesList[e].weight;

            int newCount;

            if (labels[u] == labels[v])
                newCount = cnt + 1;
            else
                newCount = 1;

            if (newCount > k)
                continue;

            ll newDist = d + w;

            if (newDist < dist[v][newCount]) {
                dist[v][newCount] = newDist;
                PUSH(((State){newDist, v, newCount}));
            }
        }
    }

    free(heap);
    free(dist);
    return -1;
}