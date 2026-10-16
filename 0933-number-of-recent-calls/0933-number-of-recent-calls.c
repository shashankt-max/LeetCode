#include <stdlib.h>

typedef struct {
    int time[10000];
    int front;
    int rear;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));

    obj->front = 0;
    obj->rear = 0;

    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->time[obj->rear++] = t;

    // Remove requests older than t - 3000
    while (obj->time[obj->front] < t - 3000) {
        obj->front++;
    }

    return obj->rear - obj->front;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}