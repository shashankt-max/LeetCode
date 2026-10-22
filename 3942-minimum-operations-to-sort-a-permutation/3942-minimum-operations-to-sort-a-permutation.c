#include <limits.h>

int minOperations(int* nums, int numsSize) {
    int n = numsSize;
    if (n <= 1) return 0;

    int idx0 = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) { idx0 = i; break; }
    }

    int asc = 1, desc = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] != (i - idx0 + n) % n) asc = 0;
        if (nums[i] != (idx0 - i + n) % n) desc = 0;
    }

    if (!asc && !desc) return -1;

    int best = INT_MAX;

    if (asc) {
        int a = idx0;                 // rotate left idx0 times
        int b = n - idx0 + 2;         // R, rotate left (n-idx0), R
        if (idx0 == 0) b = 0;         // already sorted
        best = a < b ? a : b;
    }

    if (desc) {
        int a = 1 + (idx0 + 1) % n;   // rotate left, then reverse
        int b = n - idx0;             // reverse, then rotate left
        if (a < best) best = a;
        if (b < best) best = b;
    }

    return best;
}