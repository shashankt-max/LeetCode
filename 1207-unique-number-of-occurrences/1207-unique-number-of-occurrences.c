#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    int freq[2001] = {0};
    int used[1001] = {0};

    for (int i = 0; i < arrSize; i++) {
        freq[arr[i] + 1000]++;
    }

    for (int i = 0; i < 2001; i++) {
        if (freq[i] > 0) {
            if (used[freq[i]] == 1) {
                return false;
            }

            used[freq[i]] = 1;
        }
    }

    return true;
}