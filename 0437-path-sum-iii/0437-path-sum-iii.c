int countFromNode(struct TreeNode* root, long long targetSum) {
    if (root == NULL)
        return 0;

    int count = 0;

    if (root->val == targetSum)
        count++;

    count += countFromNode(root->left, targetSum - root->val);
    count += countFromNode(root->right, targetSum - root->val);

    return count;
}

int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL)
        return 0;

    return countFromNode(root, targetSum)
         + pathSum(root->left, targetSum)
         + pathSum(root->right, targetSum);
}