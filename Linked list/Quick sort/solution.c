/*This is a function problem.You only need to complete the function given below*/
 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
}; */
//you have to complete this function
void quickSort(struct node **headRef) {
    if(*headRef==NULL)
      return;
    struct node *nptr=(*headRef)->next,*kptr=NULL,*prev=*headRef,*lptr;
    int x=(*headRef)->data;
    //cout<<x<<endl;
    while(nptr!=NULL)
    {//cout<<nptr->data<<" "; 
     if((nptr->data)<=x)
      { if(prev==NULL)
         {   lptr=kptr;
             kptr=nptr;
             nptr=nptr->next;
             kptr->next=lptr;
             *headRef=nptr;
         }
        else
         { 
             lptr=kptr;
             kptr=nptr;
             nptr=nptr->next;
             kptr->next=lptr;
             prev->next=nptr;
         }
          
      }
      else
      {prev=nptr;
       nptr=nptr->next;
      }
    }
   /*cout<<"heasdref= ";
   lptr=*headRef;
   while(lptr!=NULL)
   {
       cout<<lptr->data<<" ";
       lptr=lptr->next;
   }
   cout<<endl;
   cout<<"kptr= ";
   lptr=kptr;
   while(lptr!=NULL)
   {
       cout<<lptr->data<<" ";
       lptr=lptr->next;
   }
   cout<<endl;*/
   if(*headRef!=NULL)
   {   
       quickSort(&((*headRef)->next));
   }
   quickSort(&kptr);
  
   if(kptr!=NULL)
   {  lptr=kptr;
       while(lptr->next!=NULL)
       {
           lptr=lptr->next;
       }
      lptr->next=*headRef;
      *headRef=kptr;
   }
  
   
}
