#include <stdlib.h>

typedef struct {
    int value;
    int digitSum;
    int originalIndex;
} Item;

int getDigitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int compareItems(const void *a, const void *b) {
    const Item *x = (const Item *)a;
    const Item *y = (const Item *)b;

    if (x->digitSum != y->digitSum)
        return x->digitSum - y->digitSum;

    return x->value - y->value;
}

int minSwaps(int* nums, int numsSize) {
    Item *items = malloc(numsSize * sizeof(Item));
    int *visited = calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        items[i].value = nums[i];
        items[i].digitSum = getDigitSum(nums[i]);
        items[i].originalIndex = i;
    }

    qsort(items, numsSize, sizeof(Item), compareItems);

    int swaps = 0;

    for (int i = 0; i < numsSize; i++) {
        if (visited[i] || items[i].originalIndex == i)
            continue;

        int cycleSize = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = 1;
            j = items[j].originalIndex;
            cycleSize++;
        }

        if (cycleSize > 1)
            swaps += cycleSize - 1;
    }

    free(items);
    free(visited);

    return swaps;
}