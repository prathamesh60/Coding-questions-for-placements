
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* newNode(int value)
{
    TreeNode *nptr=(TreeNode*)malloc(sizeof(TreeNode));
    nptr->val=value;
    nptr->left=NULL;
    nptr->right=NULL;
    return nptr;
}
TreeNode* solve(vector<int> &A, vector<int> &B,int a,int k,int &r)
{
    if(a>k)
    {
        return NULL;
    }
   TreeNode *nptr=newNode(B[r]);
    r--;
   if(a==k)
    {
        
        return nptr;
    }
   else
   {
       int p=nptr->val;
       int i=a;
       while(A[i]!=p)
       {
           i++;
       }
       nptr->right=solve(A,B,i+1,k,r);
       nptr->left=solve(A,B,a,i-1,r);
       return nptr;
       
   }
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int k=A.size();
    TreeNode *root;
    int r=k-1;
    root=solve(A,B,0,k-1,r);
    return root;
}
