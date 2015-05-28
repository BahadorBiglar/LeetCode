/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
  * };
 */
int minDepth(struct TreeNode *root) {
    int min1, min2;
    
    min1 = 0;
    min2 = 0;
    
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    
    if (root->left == NULL)
        min1 = -1;
    else
        min1 = 1 + minDepth(root->left);
    if (root->right == NULL)
        min2 = -1;
    else
        min2 = 1 + minDepth(root->right);
    
    if (min1==-1)
        return min2;
    if (min2==-1)
        return min1;
    return ((min1>min2) ? min2:min1);
    
}