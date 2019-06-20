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
TreeNode* solve(vector<int> &A, vector<int> &B,int s,int e,int &r)
{
    if(s>e)
     return NULL;
    TreeNode* nptr=newNode(A[r]);
     r++;
    if(s==e)
     return nptr;
    
    int i=s,p=nptr->val;
    while(B[i]!=p)
     {
        i++;
     }
    nptr->left=solve(A,B,s,i-1,r);
    nptr->right=solve(A,B,i+1,e,r);
    return nptr;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    int k=A.size()-1;
    int r=0;
    TreeNode* root=solve(A,B,0,k,r);
    return root;
}
