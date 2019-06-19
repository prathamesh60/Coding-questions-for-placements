/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int max(int x,int y) // Function to calculate the maximum of two numbers
{
    if(x>y)
     return x;
    else
     return y;
}
/*This function checks if tree rooted at A is height balanced, if yes it returns the height
of the tree(calculated recursively) else returns -1*/
int solve(TreeNode *A) 
{                       
    if(A==NULL)
    {
        return 0;
    }
   else
   {
       int p=solve(A->left);
       int q=solve(A->right);
       if(p==-1 || q==-1)
       {
           return -1;
       }
      else if(fabs(p-q)>1)
        return -1;
      else
        {
            return (max(p,q)+1);
        }
   }
}
int Solution::isBalanced(TreeNode* A) {
    
    int k=solve(A);
    if(k==-1)
     return 0;
    else
     return 1;
}
