/*This is a function problem.You only need to complete the function given below*/
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */
/*Your method shouldn't print anything
 it should transform the passed linked list */
Node *reverse(Node *nptr)
{
    Node *head=nptr,*middle=NULL,*tail;
    while(head!=NULL)
    {
        tail=middle;
        middle=head;
        head=head->next;
        middle->next=tail;
    }
    return middle;
}
void sortList(Node** head)
{   
    if(*head!=NULL)
    {
        *head=reverse(*head);
        Node *result=*head,*nptr,*itr,*temp;
        if(result->data < 0)
        {
            nptr=result;
        }
        else
        {
           nptr=NULL;
        }
        itr=result->next;
        result->next=NULL;
        while(itr!=NULL)
        {
            if(itr->data < 0)
            { if(nptr==NULL)
               {
                   temp=itr;
                   itr=itr->next;
                   temp->next=result;
                   result=temp;
                   nptr=temp;
               }
              else
               {
                   temp=itr;
                   itr=itr->next; 
                   temp->next=nptr->next;
                   nptr->next=temp;
                   nptr=temp;
               }
                
            }
           else 
           {  if(nptr==NULL)
              { temp=itr;
                itr=itr->next; 
                temp->next=result;
                result=temp;
              }
             else
             {  temp=itr;
                itr=itr->next;
                temp->next=nptr->next;
                nptr->next=temp;
                 
             }
               
           }
          
        }
        *head=result;
    }
}
