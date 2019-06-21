/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* find_until(TreeNode* A,int B,int C,bool &v1,bool &v2)
{
    if(A==NULL)
     return NULL;
    else
    {
        if(A->val==B)
        {
            v1=true;
            return A;
        }
       if(A->val==C)
       {
           v2=true;
            return A;
       }
       TreeNode* l=find_until(A->left,B,C,v1,v2);
       TreeNode* r=find_until(A->right,B,C,v1,v2);
       if(l!=NULL && r!=NULL)
        return A;
       else if(l!=NULL)
        return l;
       else
         return r;
    }
}
bool find(TreeNode* A,int B)
{
    if(A==NULL)
     return false;
    else
     {
         if(A->val == B)
          return true;
         else
         {
             return (find(A->left,B) || find(A->right,B));
         }
     }
}
int Solution::lca(TreeNode* A, int B, int C) {
    bool v1=false,v2=false;
    TreeNode* p=find_until(A,B,C,v1,v2);
    if(p!=NULL)
    {
        if((v1 && v2) || (v1 && find(p,C)) ||(v2 && find(p,B)))
         return p->val;
        else
         return -1;
    }
   else
     return -1;
}
