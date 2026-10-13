#include <stdlib.h>

typedef struct {
    int cost;
    int index;
} Node;

void push(Node *heap, int *size, Node value) {
    int i = (*size)++;
    heap[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent].cost < heap[i].cost ||
            (heap[parent].cost == heap[i].cost &&
             heap[parent].index < heap[i].index))
            break;

        Node temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        i = parent;
    }
}

Node pop(Node *heap, int *size) {
    Node result = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size &&
            (heap[left].cost < heap[smallest].cost ||
             (heap[left].cost == heap[smallest].cost &&
              heap[left].index < heap[smallest].index)))
            smallest = left;

        if (right < *size &&
            (heap[right].cost < heap[smallest].cost ||
             (heap[right].cost == heap[smallest].cost &&
              heap[right].index < heap[smallest].index)))
            smallest = right;

        if (smallest == i)
            break;

        Node temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }

    return result;
}

long long totalCost(int* costs, int costsSize, int k, int candidates) {
    Node *leftHeap = malloc(costsSize * sizeof(Node));
    Node *rightHeap = malloc(costsSize * sizeof(Node));

    int leftSize = 0, rightSize = 0;
    int left = 0, right = costsSize - 1;

    while (left <= right && leftSize < candidates) {
        push(leftHeap, &leftSize, (Node){costs[left], left});
        left++;
    }

    while (left <= right && rightSize < candidates) {
        push(rightHeap, &rightSize, (Node){costs[right], right});
        right--;
    }

    long long answer = 0;

    for (int i = 0; i < k; i++) {
        if (rightSize == 0 ||
            (leftSize > 0 &&
             (leftHeap[0].cost < rightHeap[0].cost ||
              (leftHeap[0].cost == rightHeap[0].cost &&
               leftHeap[0].index < rightHeap[0].index)))) {

            Node hired = pop(leftHeap, &leftSize);
            answer += hired.cost;

            if (left <= right) {
                push(leftHeap, &leftSize, (Node){costs[left], left});
                left++;
            }
        } else {
            Node hired = pop(rightHeap, &rightSize);
            answer += hired.cost;

            if (left <= right) {
                push(rightHeap, &rightSize, (Node){costs[right], right});
                right--;
            }
        }
    }

    free(leftHeap);
    free(rightHeap);

    return answer;
}