/*This is a function problem.You only need to complete the function given below*/
/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/
struct Node * mergeResult(Node *node1,Node *node2)
{
    struct Node *head=NULL,*temp,*nptr1=node1,*nptr2=node2;
    while(nptr1!=NULL && nptr2!=NULL)
    { if(nptr1->data<nptr2->data)
      {
             temp=nptr1;
             nptr1=nptr1->next;
             temp->next=head;
             head=temp;
             node1=nptr1;
       
      }
      else
      {
         temp=nptr2;
         nptr2=nptr2->next;
         temp->next=head;
         head=temp;
         node2=nptr2;
          
       }
        
    }
    if(nptr1!=NULL)
    {
        while(nptr1!=NULL)
        {
             temp=nptr1;
             nptr1=nptr1->next;
             temp->next=head;
             head=temp;
             node1=nptr1;
        }
    }
    else if(nptr2!=NULL)
    {
        while(nptr2!=NULL)
        {
             temp=nptr2;
           nptr2=nptr2->next;
           temp->next=head;
           head=temp;
           node2=nptr2;
        }
    }
    return head;
}
