#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

int* successfulPairs(int* spells, int spellsSize, int* potions,
                     int potionsSize, long long success,
                     int* returnSize) {
    qsort(potions, potionsSize, sizeof(int), compare);

    int *pairs = malloc(spellsSize * sizeof(int));
    *returnSize = spellsSize;

    for (int i = 0; i < spellsSize; i++) {
        int left = 0;
        int right = potionsSize;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if ((long long)spells[i] * potions[mid] >= success)
                right = mid;
            else
                left = mid + 1;
        }

        pairs[i] = potionsSize - left;
    }

    return pairs;
}