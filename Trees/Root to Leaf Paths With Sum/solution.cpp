/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A,int B,vector<vector<int>> &ans, vector<int> &x)
{
    if(A==NULL)
    {
        if(B==0)
        {
           ans.push_back(x);    
        }
    }
   else
   {
       int k=A->val;
       x.push_back(k);
       if(A->left!=NULL && A->right!=NULL)
        {
         solve(A->left,B-k,ans,x);
         solve(A->right,B-k,ans,x);
        }
      else if(A->left!=NULL)
       {
         solve(A->left,B-k,ans,x); 
       }
      else 
       {
          solve(A->right,B-k,ans,x);
       }
       x.pop_back();
   }
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> ans;
    vector<int> x;
    solve(A,B,ans,x);
    
    return ans;
    
}
