int maxZigZag = 0;

void dfs(struct TreeNode* root, int left, int right) {
    if (root == NULL)
        return;

    if (left > maxZigZag)
        maxZigZag = left;

    if (right > maxZigZag)
        maxZigZag = right;

    // Move left -> next must move right
    if (root->left)
        dfs(root->left, right + 1, 0);

    // Move right -> next must move left
    if (root->right)
        dfs(root->right, 0, left + 1);
}

int longestZigZag(struct TreeNode* root) {
    maxZigZag = 0;
    dfs(root, 0, 0);
    return maxZigZag;
}