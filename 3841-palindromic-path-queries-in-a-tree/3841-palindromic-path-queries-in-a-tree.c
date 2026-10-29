#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool* palindromePath(int n, int** edges, int edgesSize, int* edgesColSize,
                     char* s, char** queries, int queriesSize, int* returnSize) {
    int m = 2 * (n - 1);
    int *head = (int*)malloc(n * sizeof(int));
    int *nxt  = (int*)malloc((m > 0 ? m : 1) * sizeof(int));
    int *to   = (int*)malloc((m > 0 ? m : 1) * sizeof(int));
    for (int i = 0; i < n; i++) head[i] = -1;
    int cnt = 0;
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
        to[cnt] = u; nxt[cnt] = head[v]; head[v] = cnt++;
    }

    int LOG = 1;
    while ((1 << LOG) <= n) LOG++;
    int *up    = (int*)malloc((size_t)LOG * n * sizeof(int));
    int *depth = (int*)calloc(n, sizeof(int));
    int *tin   = (int*)calloc(n, sizeof(int));
    int *tout  = (int*)calloc(n, sizeof(int));
    int *it    = (int*)malloc(n * sizeof(int));
    int *stack = (int*)malloc(n * sizeof(int));
    memcpy(it, head, n * sizeof(int));

    // iterative DFS from root 0
    int timer = 0, sp = 0;
    up[0] = 0;                 // parent of root = root
    tin[0] = timer++;
    stack[sp++] = 0;
    while (sp > 0) {
        int v = stack[sp - 1];
        int e = it[v];
        if (e != -1) {
            it[v] = nxt[e];
            int w = to[e];
            if (w == up[v]) continue;   // skip parent
            up[w] = v;
            depth[w] = depth[v] + 1;
            tin[w] = timer++;
            stack[sp++] = w;
        } else {
            tout[v] = timer - 1;
            sp--;
        }
    }

    for (int k = 1; k < LOG; k++)
        for (int v = 0; v < n; v++)
            up[k * n + v] = up[(k - 1) * n + up[(k - 1) * n + v]];

    // Fenwick tree (XOR): range update via point XORs, point query via prefix XOR
    int *bit = (int*)calloc(n + 2, sizeof(int));
    #define BIT_XOR(pos, val) do { \
        for (int _i = (pos) + 1; _i <= n + 1; _i += _i & -_i) bit[_i] ^= (val); \
    } while (0)

    int *mask = (int*)malloc(n * sizeof(int));
    for (int u = 0; u < n; u++) {
        mask[u] = 1 << (s[u] - 'a');
        BIT_XOR(tin[u], mask[u]);
        BIT_XOR(tout[u] + 1, mask[u]);
    }

    bool *ans = (bool*)malloc(queriesSize * sizeof(bool));
    int ac = 0;

    for (int qi = 0; qi < queriesSize; qi++) {
        char *q = queries[qi];
        if (q[0] == 'u') {
            int u; char c;
            sscanf(q, "update %d %c", &u, &c);
            int nw = 1 << (c - 'a');
            int d = mask[u] ^ nw;
            if (d) {
                BIT_XOR(tin[u], d);
                BIT_XOR(tout[u] + 1, d);
                mask[u] = nw;
            }
        } else {
            int u, v;
            sscanf(q, "query %d %d", &u, &v);

            // LCA via binary lifting
            int a = u, b = v;
            if (depth[a] < depth[b]) { int t = a; a = b; b = t; }
            int diff = depth[a] - depth[b];
            for (int k = 0; k < LOG; k++)
                if ((diff >> k) & 1) a = up[k * n + a];
            int w;
            if (a == b) {
                w = a;
            } else {
                for (int k = LOG - 1; k >= 0; k--) {
                    if (up[k * n + a] != up[k * n + b]) {
                        a = up[k * n + a];
                        b = up[k * n + b];
                    }
                }
                w = up[a];
            }

            // P(u) ^ P(v) ^ mask[lca]
            int x = 0;
            for (int i = tin[u] + 1; i > 0; i -= i & -i) x ^= bit[i];
            for (int i = tin[v] + 1; i > 0; i -= i & -i) x ^= bit[i];
            x ^= mask[w];

            ans[ac++] = (x & (x - 1)) == 0;
        }
    }

    free(head); free(nxt); free(to); free(up); free(depth);
    free(tin); free(tout); free(it); free(stack); free(bit); free(mask);

    *returnSize = ac;
    return ans;
}