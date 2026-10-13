/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxLevelSum(struct TreeNode* root) {
    struct TreeNode* queue[10005];
    int front = 0, rear = 0;

    queue[rear++] = root;

    long long maxSum = LLONG_MIN;
    int answer = 1;
    int level = 1;

    while (front < rear) {
        int size = rear - front;
        long long sum = 0;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            sum += node->val;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        if (sum > maxSum) {
            maxSum = sum;
            answer = level;
        }

        level++;
    }

    return answer;
}