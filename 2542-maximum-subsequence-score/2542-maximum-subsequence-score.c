#include <stdlib.h>

typedef struct {
    int num1;
    int num2;
} Pair;

int compare(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;

    return p2->num2 - p1->num2;
}

void heapPush(long long *heap, int *size, long long value) {
    int i = (*size)++;
    heap[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i])
            break;

        long long temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

long long heapPop(long long *heap, int *size) {
    long long result = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;

        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        long long temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }

    return result;
}

long long maxScore(int* nums1, int nums1Size,
                   int* nums2, int nums2Size, int k) {

    int n = nums1Size;

    Pair *pairs = malloc(n * sizeof(Pair));

    for (int i = 0; i < n; i++) {
        pairs[i].num1 = nums1[i];
        pairs[i].num2 = nums2[i];
    }

    // Sort by nums2 in descending order
    qsort(pairs, n, sizeof(Pair), compare);

    // Min-heap containing the k largest nums1 values
    long long *heap = malloc(n * sizeof(long long));

    int heapSize = 0;
    long long sum = 0;
    long long answer = 0;

    for (int i = 0; i < n; i++) {

        heapPush(heap, &heapSize, pairs[i].num1);
        sum += pairs[i].num1;

        // Keep only k largest nums1 values
        if (heapSize > k) {
            sum -= heapPop(heap, &heapSize);
        }

        // Since pairs are sorted by nums2 descending,
        // pairs[i].num2 is the minimum nums2 among selected elements.
        if (heapSize == k) {
            long long score = sum * pairs[i].num2;

            if (score > answer)
                answer = score;
        }
    }

    free(pairs);
    free(heap);

    return answer;
}