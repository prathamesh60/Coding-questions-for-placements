/*This is a function problem.You only need to complete the function given below*/
/* Following is the Linked list node structure */
/*struct Node
{
    int data;
    Node* next;
};*/
//Approach: Split the linked list from the middle. Reverse the right half and then perform alternative merge 
void reverse(Node **head)
{
    Node *h1=*head,*middle=NULL,*tail;
    while(h1!=NULL)
    {
        tail=middle;
        middle=h1;
        h1=h1->next;
        middle->next=tail;
    }
    *head=middle;
}
void reorderList(Node* head) 
{  if(head!=NULL && head->next!=NULL && head->next->next!=NULL)
   {
      Node *fast=head,*slow=head,*prev=NULL,*temp;
      while(fast!=NULL && fast->next!=NULL)
       {   prev=slow;
           slow=slow->next;
           fast=fast->next->next;
       }
      prev->next=NULL;
      reverse(&slow);
      fast=head;
      while(fast!=NULL && slow!=NULL)
      {
         prev=fast;
         fast=fast->next;
         temp=slow;
         slow=slow->next;
         temp->next=prev->next;
         prev->next=temp;
      }
      if(slow!=NULL)
      {
          temp->next=slow;
      }
      
   }
   
}
