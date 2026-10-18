#include <stdlib.h>

int compareIntervals(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    if (x[1] < y[1]) return -1;
    if (x[1] > y[1]) return 1;
    return 0;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize,
                          int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int *), compareIntervals);

    int removals = 0;
    int lastEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < lastEnd) {
            removals++;
        } else {
            lastEnd = intervals[i][1];
        }
    }

    return removals;
}