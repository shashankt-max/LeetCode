#include <stdlib.h>

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    if (root == NULL)
        return result;

    struct TreeNode* queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            if (node->left != NULL)
                queue[rear++] = node->left;

            if (node->right != NULL)
                queue[rear++] = node->right;

            // Last node of this level
            if (i == levelSize - 1)
                result[(*returnSize)++] = node->val;
        }
    }

    return result;
}