#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool present[2001];
    int smallest;
} SmallestInfiniteSet;

SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet* obj =
        (SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));

    for (int i = 1; i <= 2000; i++)
        obj->present[i] = true;

    obj->smallest = 1;

    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    int result = obj->smallest;

    obj->present[result] = false;

    obj->smallest++;

    while (!obj->present[obj->smallest])
        obj->smallest++;

    return result;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    if (obj->present[num])
        return;

    obj->present[num] = true;

    if (num < obj->smallest)
        obj->smallest = num;
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj);
}