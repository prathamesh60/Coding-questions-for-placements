/*This is a function problem.You only need to complete the function given below*/
/* Structure of the linked list node is as
struct node
{
    int data;
    struct node* next;
};
*/
/* Function to mergesort the linked list
 *  headRef: reference to the head of the linked list
 */
struct node* mergeself(struct node* a,struct node *b)
{   struct node *result=NULL;
    if(a==NULL)
    {
        result=b;
    }
    else if(b==NULL)
    {
       result=a;
    }
    else
    {
        if(a->data < b->data)
        {
            result=a;
            result->next=mergeself(a->next,b);
        }
        else
        {
            result=b;
            result->next=mergeself(a,b->next);
        }
    }
    return result;
}
void mergeSort(struct node** headRef) {
    if(*headRef!=NULL && (*headRef)->next!=NULL)
    {
        struct node *nptr=*headRef,*prev=NULL,*middle=*headRef;
        while(nptr!=NULL && nptr->next!=NULL)
        { prev=nptr;
          middle=nptr->next;
          nptr=nptr->next->next;
        }
       prev->next=NULL;
       mergeSort(headRef);
       mergeSort(&middle);
       *headRef=mergeself(*headRef,middle);
    }

}
