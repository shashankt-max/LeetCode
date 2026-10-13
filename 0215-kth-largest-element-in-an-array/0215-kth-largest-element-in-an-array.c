void heapifyUp(int *heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;

        if (heap[parent] <= heap[idx])
            break;

        int temp = heap[parent];
        heap[parent] = heap[idx];
        heap[idx] = temp;

        idx = parent;
    }
}

void heapifyDown(int *heap, int size, int idx) {
    while (1) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == idx)
            break;

        int temp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = temp;

        idx = smallest;
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int *heap = (int *)malloc(sizeof(int) * k);
    int size = 0;

    for (int i = 0; i < numsSize; i++) {
        if (size < k) {
            heap[size] = nums[i];
            heapifyUp(heap, size);
            size++;
        } else if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
    }

    int ans = heap[0];
    free(heap);
    return ans;
}