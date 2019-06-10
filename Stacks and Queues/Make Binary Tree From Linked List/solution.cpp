/*This is a function problem.You only need to complete the function given below*/
/*
The structure of Link list node is as follows 
struct node
{
    int data;
    struct node* next;
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/
/*You are required to complete this method*/
TreeNode* make_node(int data)
{
    TreeNode *kptr=(TreeNode*)malloc(sizeof(TreeNode));
    kptr->data=data;
    kptr->left=NULL;
    kptr->right=NULL;
    return kptr;
}
void convert(node *head,TreeNode * &root)
{
   queue<TreeNode*> qu;
   node *nptr=head;
   TreeNode *kptr=make_node(nptr->data);
   qu.push(kptr);
   root=kptr;
   nptr=nptr->next;
   while(nptr!=NULL)
   {
       kptr=qu.back();
       qu.pop();
       TreeNode* lptr;
       lptr=make_node(nptr->data);
       kptr->left=lptr;
       qu.push(lptr);
       nptr=nptr->next;
       if(nptr!=NULL)
       {
         lptr=make_node(nptr->data);
         kptr->right=lptr;
         qu.push(lptr);
         nptr=nptr->next;
       }
   }
}
    
