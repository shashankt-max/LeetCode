#include <stdlib.h>

#define MOD 1000000007LL

typedef struct {
    long long sum;
    long long sqSum;
    long long lazy;
} Node;

Node tree[400005];

void apply(int node, int left, int right, long long val) {
    long long len = right - left + 1;

    tree[node].sqSum =
        (tree[node].sqSum
         + 2LL * val * tree[node].sum
         + len * val % MOD * val) % MOD;

    tree[node].sum =
        (tree[node].sum + len * val) % MOD;

    tree[node].lazy =
        (tree[node].lazy + val) % MOD;
}

void push(int node, int left, int right) {
    if (tree[node].lazy == 0 || left == right)
        return;

    int mid = left + (right - left) / 2;
    long long val = tree[node].lazy;

    apply(node * 2, left, mid, val);
    apply(node * 2 + 1, mid + 1, right, val);

    tree[node].lazy = 0;
}

void update(int node, int left, int right,
            int ql, int qr, long long val) {
    if (ql > right || qr < left)
        return;

    if (ql <= left && right <= qr) {
        apply(node, left, right, val);
        return;
    }

    push(node, left, right);

    int mid = left + (right - left) / 2;

    update(node * 2, left, mid, ql, qr, val);
    update(node * 2 + 1, mid + 1, right, ql, qr, val);

    tree[node].sum =
        (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

    tree[node].sqSum =
        (tree[node * 2].sqSum + tree[node * 2 + 1].sqSum) % MOD;
}

int sumCounts(int* nums, int numsSize) {
    for (int i = 0; i < 4 * numsSize + 5; i++) {
        tree[i].sum = 0;
        tree[i].sqSum = 0;
        tree[i].lazy = 0;
    }

    int *last = calloc(100001, sizeof(int));
    long long answer = 0;

    for (int i = 1; i <= numsSize; i++) {
        int x = nums[i - 1];

        update(1, 1, numsSize, last[x] + 1, i, 1);

        answer = (answer + tree[1].sqSum) % MOD;
        last[x] = i;
    }

    free(last);
    return (int)answer;
}