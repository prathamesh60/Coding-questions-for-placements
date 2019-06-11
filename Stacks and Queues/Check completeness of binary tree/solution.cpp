/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> qu;
        TreeNode *nptr=root;
        int flag=0;
        if(root->right!=NULL && root->left==NULL)
            return false;
        else if((root->left!=NULL && root->right==NULL)  ||(root->left==NULL && root->right==NULL))
        {
            flag=1;
        }
        if(root->left!=NULL)
        qu.push(root->left);
        if(root->right!=NULL)
          qu.push(root->right);
        while((!qu.empty())&& flag==0)
        {   root=qu.front();
            qu.pop();
             if(root->right!=NULL && root->left==NULL)
            return false;
        else if((root->left!=NULL && root->right==NULL)  ||(root->left==NULL && root->right==NULL))
        {
            flag=1;
        }
        if(root->left!=NULL)
        qu.push(root->left);
        if(root->right!=NULL)
          qu.push(root->right);
        }
        root=nptr;
      while((!qu.empty()) && flag==1)
      {  nptr=qu.front();
         qu.pop();
         if(nptr->left!=NULL || nptr->right!=NULL)
             return false;
      }
      return true;
    }
};
