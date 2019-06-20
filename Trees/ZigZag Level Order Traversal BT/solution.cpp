/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
  vector<vector<int>> ans;
  if(A!=NULL)
  {
    stack<TreeNode*> st1,st2;
    int flag=1;
    st1.push(A);
    
    //vector<int> p;
   // p.push_back(A->val);
   // ans.push_back(p);
    while((!st1.empty()) || (!st2.empty()))
    {
        
        if(flag==1)
        { int k=st1.size();
           vector<int> p1;
           int i;
           for(i=0;i<k;i++)
           {
               TreeNode *nptr=st1.top();
               st1.pop();
               p1.push_back(nptr->val);
               if(nptr->left!=NULL)
                st2.push(nptr->left);
               if(nptr->right!=NULL)
                st2.push(nptr->right);
           }
           ans.push_back(p1);
        }
        else
        {  int k=st2.size();
            vector<int> p1;
           int i;
           for(i=0;i<k;i++)
           {
               TreeNode *nptr=st2.top();
               st2.pop();
               p1.push_back(nptr->val);
               if(nptr->right!=NULL)
                st1.push(nptr->right);
               if(nptr->left!=NULL)
                st1.push(nptr->left);
           }
           ans.push_back(p1);
        }
       flag*=-1;
    }

      
  }     
  return ans;
}
