int maxi(int x,int y)
{
    if(x>y)
     return x;
    else
     return y;
}
int find(struct Node *root,int& max)
{
    if(root==NULL)
     {
         return 0;
     }
    else if(root->left==NULL || root->right==NULL)
    {
        //return (root->data+);
        int p=maxi(find(root->left,max),find(root->right,max));
        return root->data+p;
    }
    else
     {
         int p=find(root->left,max);
         int q=find(root->right,max);
         if(p+q+root->data >max)
           max=p+q+root->data;
         return maxi(p,q) + root->data;
     }
}
int maxPathSum(struct Node *root)
{
   int max=INT_MIN;
   int k=find(root,max);
   return max;
}
