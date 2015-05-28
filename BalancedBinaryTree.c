/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int GetHeight(struct TreeNode *root) {
    if (root==NULL)
        return 0;
    int H1, H2;
    H1 = GetHeight(root->left);
    H2 = GetHeight(root->right);
    return (1 + (H1 > H2 ? H1:H2));
}

bool isBalanced(struct TreeNode *root) {
    if (root==NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (abs((GetHeight(root->left)) - (GetHeight(root->right))) > 1)
        return false;
    if (!isBalanced(root->left))
        return false;
    if (!isBalanced(root->right))
        return false;
    return true;
}