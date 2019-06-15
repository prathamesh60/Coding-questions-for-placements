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

Node* copyList(Node* A) {
    Node *nptr=A,*copy=NULL,*kptr,*temp;
    if(nptr!=NULL)
    {
        while(nptr!=NULL)
        {
            temp=nptr;
            nptr=nptr->next;
            kptr=(Node*)malloc(sizeof(Node));
            kptr->data=temp->data;
            kptr->next=temp->next;
            temp->next=kptr;
            if(copy==NULL)
            {
                copy=kptr;
            }
        }
       nptr=A;
       while(nptr!=NULL)
       {   temp=nptr;
           kptr=nptr->next;
           nptr=kptr->next;
           if(temp->arb==NULL)
            {
              kptr->arb=NULL;
            }
           else
            {
              kptr->arb=temp->arb->next;
            }
       }
       nptr=A;
       while(nptr!=NULL)
       {
           temp=nptr;
           kptr=nptr->next;
           nptr=kptr->next;
           if(nptr!=NULL)
           {
               kptr->next=nptr->next;
           }
          temp->next=nptr;
       }
       //while()
     }
   /* if(copy!=NULL)
    cout<<copy->label;*/
    return copy;
}

