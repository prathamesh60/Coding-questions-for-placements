/*This is a function problem.You only need to complete the function given below*/
/* The Node is defined 
  struct Node
  {
     int data;
     Node *next;
  } */
/*The function below returns an int denoting
the length of the longest palindrome list. */
int find(Node *a,Node * b)
{
    int result=0;
    while(a!=NULL && b!=NULL && a->data== b->data)
    {
        result++;
        a=a->next;
        b=b->next;
    }
    return result;
}
int max(int x,int y)
{
    if(x>y)
     return x;
    else
     return y;
}
int maxPalindrome(Node *head)
{
   Node *curr=head,*prev=NULL,*nptr;
   int result=0;
   while(curr!=NULL)
   {  nptr=curr->next;
      curr->next=prev;
      result=max(result,2*find(prev,nptr)+1);
      result=max(result,2*find(curr,nptr));
      prev=curr;
      curr=nptr;
   }
   return result;
}
