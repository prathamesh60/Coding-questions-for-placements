/*This is a function problem.You only need to complete the function given below*/
/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
    the flattened linked list. */
Node *merge(Node *a,Node* b)
{   Node *result;
    if(a==NULL && b==NULL)
     result=NULL;
    else if(a==NULL)
     result=b;
    else if(b==NULL)
     result=a;
    else
    {
        if((a->data) < (b->data))
        {
            result=a;
            result->bottom=merge(a->bottom,b);
        }
       else
       {
           result=b;
           result->bottom=merge(a,b->bottom);
       }
    }
    return result;
}
Node *flatten(Node *root)
{ if(root==NULL || root->next==NULL)
   {
       return root;
   }
  else
   {
     root=merge(root,flatten(root->next));
     Node *nptr=root;
     while(nptr!=NULL)
     {
        nptr->next=nptr->bottom;
        nptr=nptr->bottom;
        
     }
     return root;
   }
}
