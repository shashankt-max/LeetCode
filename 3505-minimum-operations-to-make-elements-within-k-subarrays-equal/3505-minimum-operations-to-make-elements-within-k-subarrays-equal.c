
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef long long ll;

#define INF (LLONG_MAX / 4)

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int lowerBound(int *a, int n, int target) {
    int l = 0, r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

void update(ll *bit, int n, int idx, ll val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

ll prefix(ll *bit, int idx) {
    ll result = 0;

    while (idx > 0) {
        result += bit[idx];
        idx -= idx & -idx;
    }

    return result;
}

int kth(ll *bit, int n, int k) {
    int idx = 0;

    int step = 1;
    while (step * 2 <= n)
        step *= 2;

    for (; step > 0; step /= 2) {
        int next = idx + step;

        if (next <= n && bit[next] < k) {
            idx = next;
            k -= (int)bit[next];
        }
    }

    return idx + 1;
}

ll windowCost(ll *cnt, ll *sum, int *sorted, int m, int x) {
    int mid = kth(cnt, m, (x + 1) / 2);
    ll median = sorted[mid - 1];

    ll leftCount = prefix(cnt, mid);
    ll leftSum = prefix(sum, mid);

    ll totalSum = prefix(sum, m);
    ll totalCount = prefix(cnt, m);

    ll rightCount = totalCount - leftCount;
    ll rightSum = totalSum - leftSum;

    return median * leftCount - leftSum
         + rightSum - median * rightCount;
}

long long minOperations(int* nums, int numsSize, int x, int k) {
    int n = numsSize;

    // Coordinate compression
    int *sorted = malloc(n * sizeof(int));
    memcpy(sorted, nums, n * sizeof(int));

    qsort(sorted, n, sizeof(int), cmp);

    int m = 0;

    for (int i = 0; i < n; i++) {
        if (m == 0 || sorted[i] != sorted[m - 1])
            sorted[m++] = sorted[i];
    }

    // Fenwick trees
    ll *cnt = calloc(m + 1, sizeof(ll));
    ll *sum = calloc(m + 1, sizeof(ll));

    // DP arrays
    ll **dp = malloc((k + 1) * sizeof(ll *));

    for (int j = 0; j <= k; j++) {
        dp[j] = malloc((n + 1) * sizeof(ll));

        for (int i = 0; i <= n; i++)
            dp[j][i] = INF;
    }

    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;

    // Sliding window + DP
    for (int i = 1; i <= n; i++) {

        int idx = lowerBound(sorted, m, nums[i - 1]) + 1;

        update(cnt, m, idx, 1);
        update(sum, m, idx, nums[i - 1]);

        if (i > x) {
            int old = lowerBound(sorted, m, nums[i - x - 1]) + 1;

            update(cnt, m, old, -1);
            update(sum, m, old, -(ll)nums[i - x - 1]);
        }

        for (int j = 1; j <= k; j++) {
            dp[j][i] = dp[j][i - 1];

            if (i >= x && i >= j * x) {
                ll cost = windowCost(cnt, sum, sorted, m, x);

                ll candidate = dp[j - 1][i - x] + cost;

                if (candidate < dp[j][i])
                    dp[j][i] = candidate;
            }
        }
    }

    ll answer = dp[k][n];

    for (int j = 0; j <= k; j++)
        free(dp[j]);

    free(dp);
    free(cnt);
    free(sum);
    free(sorted);

    return answer;
}
