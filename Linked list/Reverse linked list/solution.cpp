Node* reverseList(Node *head)
{
  Node *head1=head,*middle=NULL,*tail;
  while(head1!=NULL)
  {
      tail=middle;
      middle=head1;
      head1=head1->next;
      middle->next=tail;
  }
  return middle;
}
