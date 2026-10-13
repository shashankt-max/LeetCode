int countGoodNodes(struct TreeNode* root, int maxValue) {
    if (root == NULL)
        return 0;

    int good = 0;

    if (root->val >= maxValue)
        good = 1;

    if (root->val > maxValue)
        maxValue = root->val;

    return good
         + countGoodNodes(root->left, maxValue)
         + countGoodNodes(root->right, maxValue);
}

int goodNodes(struct TreeNode* root) {
    return countGoodNodes(root, root->val);
}