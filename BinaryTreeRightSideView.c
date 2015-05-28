/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * Fill out 'n' to indicate how many elements return.
 */
int *rightSideView(struct TreeNode *root, int *n) {
    int n1, n2, *answer1, *answer2, *answer3;
    if (root==NULL){
        *n=0;
        return NULL;
    }
    

    answer3 = (int *)malloc(20*sizeof(int));
    
    answer1 = rightSideView(root->left,  &n1);
    answer2 = rightSideView(root->right, &n2);
    
    *n = 1+((n1>n2)?n1:n2);
    answer3[0]=root->val;
    for (int i = 1; i<(*n); i++)
        answer3[i]=((i-1<n2) ? answer2[i-1]:answer1[i-1]);
    
    free(answer1);
    free(answer2);
    return answer3;
}