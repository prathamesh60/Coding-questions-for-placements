/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL && B==NULL) //if both are NULL then true
    {
        return 1;
    }
   else if(A==NULL || B==NULL) //if one of them is Null then false
   {
       return 0;
   }
   else
   {
       if(A->val!=B->val) //If values of both root are differnt then false
        return 0;
       else
       {
           int p=isSameTree(A->left,B->left);  //check if both left and right subtrees are identical
           int q=isSameTree(A->right,B->right);
           if(p==1 && q==1)
            return 1;
           else
             return 0;
       }
   }
   
}
