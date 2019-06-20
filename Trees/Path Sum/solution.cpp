/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    if(A==NULL)
    {
        if(B==0)
         return 1;
        else
         return 0;
    }
   else
   {  int k=A->val;
      if(A->left!=NULL && A->right!=NULL)
       return ( (hasPathSum(A->left,B-k) ) || (hasPathSum(A->right,B-k)) );
      else if(A->left!=NULL)
       return(hasPathSum(A->left,B-k));
      else 
       return (hasPathSum(A->right,B-k));
      
   }
}
