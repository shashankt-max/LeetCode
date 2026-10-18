#include <stdlib.h>

int comparePoints(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    if (x[1] < y[1]) return -1;
    if (x[1] > y[1]) return 1;
    return 0;
}

int findMinArrowShots(int** points, int pointsSize,
                      int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int *), comparePoints);

    int arrows = 1;
    long long end = points[0][1];

    for (int i = 1; i < pointsSize; i++) {
        if ((long long)points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }

    return arrows;
}