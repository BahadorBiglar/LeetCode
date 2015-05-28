/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int maxDepth(struct TreeNode *root) {
    if (root == NULL)
        return 0;
    int max1 = 1 + maxDepth(root->left);
    int max2 = 1 + maxDepth(root->right);
    if(max1> max2)
        return max1;
    return max2;
}