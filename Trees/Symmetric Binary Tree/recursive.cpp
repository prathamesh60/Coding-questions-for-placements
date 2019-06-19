/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ismirror(TreeNode* A,TreeNode* B)
{
    if(A==NULL || B==NULL) 
     return (A==B);
    else if(A->val == B->val)
     {
        return ((ismirror(A->left,B->right)) && (ismirror(A->right,B->left)));
     }
    else
     return 0;
}
int Solution::isSymmetric(TreeNode* A) {
   
    
   return ismirror(A,A);
}
