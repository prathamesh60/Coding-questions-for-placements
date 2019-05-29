/*This is a function problem.You only need to complete the function given below*/
/*
  Reverse a linked list
  The input list will have at least one element  
  Return pointer to head of reverse linked list 
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *reverse (struct node *head, int k)
{ 
   struct node *prev=NULL,*curr=head,*head2,*middle2,*tail2,*nptr;
   int j;
   while(curr!=NULL)
   {
       head2=curr;
       nptr=curr;
       j=0;
       while(nptr!=NULL && j<k)
       {   nptr=nptr->next;
           j++;
       }
      middle2=nptr;
      while(head2!=nptr)
      {
          tail2=middle2;
          middle2=head2;
          head2=head2->next;
          middle2->next=tail2;
      }
      if(prev==NULL)
      {
          head=middle2;
      }
      else
      {
          prev->next=middle2;
      }
      prev=curr;
      curr=head2;
   }
   return head;
}
