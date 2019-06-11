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
    int count(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        else
        {
            int c=1;
            c+=count(root->left);
            c+=count(root->right);
           return c;
        }
    }
    bool is_complete(TreeNode* root,int index,int count)
    {
       if(root==NULL)
       {
           return true;
       }
       else
       {
           if(index>=count)
           {
               return false;
           }
          bool k1=true;;
         return (is_complete(root->left,2*index+1,count) && is_complete(root->right,2*index+2,count));
          
       }
    }
    bool isCompleteTree(TreeNode* root) {
      int c=count(root);
     // cout<<c<<endl;
      int i=0;
      return is_complete(root,i,c);
      
    }
    
    
};
