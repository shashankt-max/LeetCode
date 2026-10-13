/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left)
        node = node->left;
    return node;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node found

        // Case 1: No left child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: No right child
        if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct TreeNode* successor = findMin(root->right);

        root->val = successor->val;

        root->right = deleteNode(root->right, successor->val);
    }

    return root;
}