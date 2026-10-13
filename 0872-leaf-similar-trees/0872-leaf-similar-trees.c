void getLeaves(struct TreeNode* root, int arr[], int* size) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        arr[(*size)++] = root->val;
        return;
    }

    getLeaves(root->left, arr, size);
    getLeaves(root->right, arr, size);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaves1[200], leaves2[200];
    int size1 = 0, size2 = 0;

    getLeaves(root1, leaves1, &size1);
    getLeaves(root2, leaves2, &size2);

    if (size1 != size2)
        return false;

    for (int i = 0; i < size1; i++) {
        if (leaves1[i] != leaves2[i])
            return false;
    }

    return true;
}