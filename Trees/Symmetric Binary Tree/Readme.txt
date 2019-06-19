/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSymmetric(TreeNode* A) {
   if(A==NULL)
    return true;
   queue <TreeNode*> q1,q2;
  if(A->left!=NULL)
    q1.push(A->left);
  if(A->right!=NULL)
    {
        q2.push(A->right);
    }
  while(!q1.empty() || !q2.empty())
  {
      
      if(q1.size()!=q2.size())
       return 0;
      TreeNode *kptr,*nptr;
      int k1=q1.size();
      int i;
      for(i=0;i<k1;i++)
      {
          kptr=q1.front();
          nptr=q2.front();
          q1.pop();
          q2.pop();
          if(kptr->val!=nptr->val)
           return 0;
          if(kptr->left!=NULL)
           {
               q1.push(kptr->left);
           }
          if(kptr->right!=NULL)
           {
              q1.push(kptr->right);
           }
         if(nptr->right!=NULL)
           {
              q2.push(nptr->right);
           }
         if(nptr->left!=NULL)
           {
              q2.push(nptr->left);
           }
        
      }
   }
  return 1;
}
