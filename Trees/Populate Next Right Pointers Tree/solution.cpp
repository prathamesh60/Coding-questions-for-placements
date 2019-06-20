/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
   if(A!=NULL)
   {
    TreeLinkNode *nptr=A;
    nptr->next=NULL;
    while(nptr!=NULL)
    {   TreeLinkNode *next=NULL;
        TreeLinkNode  *kptr=nptr,*prev=NULL;
        while(kptr!=NULL)
        { TreeLinkNode *x,*y;
          if(kptr->left!=NULL)
           {
               x=kptr->left;
               if(prev!=NULL)
               {
                   prev->next=x;
               }
              else
              {
                  next=x;
              }
               prev=x;
               x->next=NULL;
               
           }
          if(kptr->right!=NULL)
          {
              y=kptr->right;
              if(prev!=NULL)
              {
                  prev->next=y;
              }
             else
             {
                 next=y;
             }
             prev=y;
             y->next=NULL;
          }
          
         kptr=kptr->next;
       }
       nptr=next;
    }
    
   }
   
}
