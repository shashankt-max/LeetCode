
#include <stdlib.h>

typedef struct {
    int server;
    int time;
} Log;

typedef struct {
    int time;
    int index;
} Query;

int cmpLog(const void *a, const void *b) {
    Log *x = (Log *)a;
    Log *y = (Log *)b;
    return (x->time > y->time) - (x->time < y->time);
}

int cmpQuery(const void *a, const void *b) {
    Query *x = (Query *)a;
    Query *y = (Query *)b;
    return (x->time > y->time) - (x->time < y->time);
}

int* countServers(int n, int** logs, int logsSize,
                  int* logsColSize, int x,
                  int* queries, int queriesSize,
                  int* returnSize) {

    Log *sortedLogs = malloc(logsSize * sizeof(Log));
    Query *sortedQueries = malloc(queriesSize * sizeof(Query));

    int *answer = malloc(queriesSize * sizeof(int));
    int *freq = calloc(n + 1, sizeof(int));

    *returnSize = queriesSize;

    // Copy and sort logs
    for (int i = 0; i < logsSize; i++) {
        sortedLogs[i].server = logs[i][0];
        sortedLogs[i].time = logs[i][1];
    }

    qsort(sortedLogs, logsSize, sizeof(Log), cmpLog);

    // Store queries with their original indices
    for (int i = 0; i < queriesSize; i++) {
        sortedQueries[i].time = queries[i];
        sortedQueries[i].index = i;
    }

    qsort(sortedQueries, queriesSize, sizeof(Query), cmpQuery);

    int left = 0;
    int right = 0;
    int active = 0;

    for (int i = 0; i < queriesSize; i++) {
        int t = sortedQueries[i].time;

        // Add logs up to current query time
        while (right < logsSize && sortedLogs[right].time <= t) {
            int id = sortedLogs[right].server;

            if (freq[id] == 0)
                active++;

            freq[id]++;
            right++;
        }

        // Remove logs outside the inclusive window
        while (left < right && sortedLogs[left].time < t - x) {
            int id = sortedLogs[left].server;

            freq[id]--;

            if (freq[id] == 0)
                active--;

            left++;
        }

        answer[sortedQueries[i].index] = n - active;
    }

    free(sortedLogs);
    free(sortedQueries);
    free(freq);

    return answer;
}
