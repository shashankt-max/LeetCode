#include <stdlib.h>
#include <math.h>

long long minSumSquareDiff(int* nums1, int nums1Size,
                           int* nums2, int nums2Size,
                           int k1, int k2) {
    int n = nums1Size;
    int *diff = (int *)malloc(n * sizeof(int));

    long long k = (long long)k1 + k2;
    int maxDiff = 0;
    long long total = 0;

    for (int i = 0; i < n; i++) {
        diff[i] = abs(nums1[i] - nums2[i]);
        total += diff[i];

        if (diff[i] > maxDiff)
            maxDiff = diff[i];
    }

    if (total <= k) {
        free(diff);
        return 0;
    }

    int left = 0, right = maxDiff;

    // Binary search for the minimum possible maximum difference
    while (left < right) {
        int mid = left + (right - left) / 2;
        long long needed = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > mid)
                needed += diff[i] - mid;
        }

        if (needed <= k)
            right = mid;
        else
            left = mid + 1;
    }

    int limit = left;
    long long needed = 0;
    long long ans = 0;
    long long count = 0;

    for (int i = 0; i < n; i++) {
        if (diff[i] > limit)
            needed += diff[i] - limit;

        int d = diff[i] < limit ? diff[i] : limit;
        ans += (long long)d * d;

        if (diff[i] >= limit)
            count++;
    }

    long long remaining = k - needed;

    // Reduce 'remaining' differences from limit to limit - 1
    ans -= remaining * (2LL * limit - 1);

    free(diff);
    return ans;
}