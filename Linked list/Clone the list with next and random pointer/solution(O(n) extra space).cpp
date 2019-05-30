/*This is a function problem.You only need to complete the function given below*/
/*  the node structure is as follows
struct Node {
    int data;
    Node *next;
    Node *arb;
    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/
// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *newnode(int data)
{ Node *nptr=(Node*)malloc(sizeof(Node));
  nptr->next=NULL;
  nptr->arb=NULL;
  nptr->data=data;
  return nptr;
}
Node *copyList(Node *head) {
    //Here we create hashmap between original list and copy list 
     //And then clone the list
     map<Node*,Node*> m;
     Node *curr=head;
     Node *copy=NULL,*kptr;
    // m[NULL]=NULL;
     while(curr!=NULL)
     {
        kptr=newnode(curr->data);
        m[curr]=kptr;
        curr=curr->next;
     }
     curr=head;
    // copy=m[curr];
     while(curr!=NULL)
     {
         copy=m[curr];
         if(curr->next!=NULL)
          copy->next=m[curr->next];
         else
          copy->next=NULL;
         
         copy->arb=m[curr->arb];
         curr=curr->next;
     }
     return m[head];
     
}
