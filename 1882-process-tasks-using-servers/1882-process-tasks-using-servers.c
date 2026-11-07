
#include <stdlib.h>

typedef struct {
    int weight;
    int index;
    long long freeTime;
} Server;

typedef struct {
    Server *arr;
    int size;
} MinHeap;

int compare(Server a, Server b, int type) {
    if (type == 0) {
        if (a.weight != b.weight)
            return a.weight < b.weight;
        return a.index < b.index;
    }

    if (a.freeTime != b.freeTime)
        return a.freeTime < b.freeTime;

    if (a.weight != b.weight)
        return a.weight < b.weight;

    return a.index < b.index;
}

void push(MinHeap *h, Server val, int type) {
    int i = ++h->size;
    h->arr[i] = val;

    while (i > 1 && compare(h->arr[i], h->arr[i / 2], type)) {
        Server temp = h->arr[i];
        h->arr[i] = h->arr[i / 2];
        h->arr[i / 2] = temp;
        i /= 2;
    }
}

Server pop(MinHeap *h, int type) {
    Server result = h->arr[1];
    Server last = h->arr[h->size--];

    if (h->size == 0)
        return result;

    h->arr[1] = last;

    int i = 1;

    while (1) {
        int smallest = i;
        int l = 2 * i;
        int r = 2 * i + 1;

        if (l <= h->size &&
            compare(h->arr[l], h->arr[smallest], type))
            smallest = l;

        if (r <= h->size &&
            compare(h->arr[r], h->arr[smallest], type))
            smallest = r;

        if (smallest == i)
            break;

        Server temp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = temp;

        i = smallest;
    }

    return result;
}

int* assignTasks(int* servers, int serversSize,
                 int* tasks, int tasksSize,
                 int* returnSize) {

    int n = serversSize;
    int m = tasksSize;

    *returnSize = m;

    int *ans = malloc(m * sizeof(int));

    MinHeap freeHeap, busyHeap;

    freeHeap.arr = malloc((n + 1) * sizeof(Server));
    busyHeap.arr = malloc((n + m + 1) * sizeof(Server));

    freeHeap.size = 0;
    busyHeap.size = 0;

    // Initially, all servers are free.
    for (int i = 0; i < n; i++) {
        Server s = {servers[i], i, 0};
        push(&freeHeap, s, 0);
    }

    long long time = 0;

    for (int j = 0; j < m; j++) {

        if (time < j)
            time = j;

        // Move all servers that have finished into freeHeap.
        while (busyHeap.size > 0 &&
               busyHeap.arr[1].freeTime <= time) {

            Server s = pop(&busyHeap, 1);
            push(&freeHeap, s, 0);
        }

        // If no server is free, jump to the next finishing time.
        if (freeHeap.size == 0) {
            time = busyHeap.arr[1].freeTime;

            while (busyHeap.size > 0 &&
                   busyHeap.arr[1].freeTime <= time) {

                Server s = pop(&busyHeap, 1);
                push(&freeHeap, s, 0);
            }
        }

        // Assign the task to the best available server.
        Server s = pop(&freeHeap, 0);

        ans[j] = s.index;

        s.freeTime = time + tasks[j];

        push(&busyHeap, s, 1);
    }

    free(freeHeap.arr);
    free(busyHeap.arr);

    return ans;
}
