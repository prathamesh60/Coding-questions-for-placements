/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *newNode(int value)
{
    TreeNode *nptr=(TreeNode*)malloc(sizeof(TreeNode));
    nptr->val=value;
    nptr->left=NULL;
    nptr->right=NULL;
    return nptr;
}
TreeNode* solve(vector<int> &A,int a,int b)
{
    if(a>b)
     return NULL;
    else if(a==b)
    {
      TreeNode *nptr=newNode(A[a]);
      return nptr;
    }
   else
   {
       int i,max=INT_MIN,ind=-1;
       for(i=a;i<=b;i++)
       {
           if(max<=A[i])
           {
               max=A[i];
               ind=i;
           }
       }
      TreeNode *nptr=newNode(max);
      nptr->left=solve(A,a,ind-1);
      nptr->right=solve(A,ind+1,b);
      return nptr;
   }
}
TreeNode* Solution::buildTree(vector<int> &A) {
    int s=A.size();
    TreeNode *root;
    root=solve(A,0,s-1);
    return root;
}
