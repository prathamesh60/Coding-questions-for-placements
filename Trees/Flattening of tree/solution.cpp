/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A==NULL)
    {
        return NULL;
    }
   else if(A->left==NULL)
   {
      A->right=flatten(A->right);
      return A;
   }
   else
   {
       A->left=flatten(A->left);
       TreeNode* nptr=A->right;
       TreeNode* kptr=A->left;
       A->right=kptr;
       while(kptr->right!=NULL)
       {
           kptr=kptr->right;
       }
      kptr->right=flatten(nptr);
      A->left=NULL;
      return A;
   }
}
