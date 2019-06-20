/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode *root,TreeNode* &first,TreeNode* &middle,TreeNode* &last,TreeNode* &prev)
{
   if(root!=NULL)
   {
       solve(root->left,first,middle,last,prev);
       if(prev!=NULL && prev->val > root->val)
       {
          if(first==NULL)
          {
              first=prev;
              middle=root;
          }
         else if(last==NULL)
          {
              last=root;
          }
         
       }
       prev=root;
       solve(root->right,first,middle,last,prev);
   }
}
vector<int> Solution::recoverTree(TreeNode* A) {
    
   // TreeNode *p=NULL;
    TreeNode *first,*middle,*last,*prev;
    first=middle=last=prev=NULL;
    solve(A,first,middle,last,prev);
    vector<int> ans;
    if(first!=NULL && last!=NULL)
    {
        ans.push_back(first->val);
        ans.push_back(last->val);
    }
   else if(first!=NULL)
    {
       ans.push_back(first->val);
       ans.push_back(middle->val);
    }
    sort(ans.begin(),ans.end());
    return ans;
    
}
