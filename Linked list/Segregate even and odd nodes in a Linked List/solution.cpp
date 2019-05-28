#include <iostream>
using namespace std;
typedef struct node_tag 
{
    int data;
    struct node_tag* next;
    
}node;
void Traverse(node *nptr)
{
    while(nptr!=NULL)
    {
        cout<<nptr->data<<" ";
        nptr=nptr->next;
    }
    cout<<endl;
}
node *func(node *head)
{
    node *even=NULL,*nptr=head,*prev=NULL,*temp;
    while(nptr!=NULL)
    {
        if((nptr->data)%2!=0)
        {
            prev=nptr;
            nptr=nptr->next;
        }
       else
        {
            if(prev==even)
            {
                prev=even=nptr;
                nptr=nptr->next;
            }
           else
           {
              if(even==NULL)
              {
                  temp=nptr;
                  nptr=nptr->next;
                  prev->next=nptr;
                  temp->next=head;
                  head=temp;
                  even=temp;
              }
             else
              {
                  temp=nptr;
                  nptr=nptr->next;
                  prev->next=nptr;
                  temp->next=even->next;
                  even->next=temp;
                  even=temp;
              }
           }
        }
    }
    return head;
    
}
int main() {
    int t,n,i,j,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        node *head=NULL,*tail=NULL;
        for(j=0;j<n;j++)
        {  cin>>k;
          node *nptr=(node*)malloc(sizeof(node));
          nptr->next=NULL;
          nptr->data=k;
          if(head==NULL)
          {
              head=nptr;
              tail=nptr;
              
          }
          else
          {
              tail->next=nptr;
              tail=nptr;
          }
          
        }
        head=func(head);
        Traverse(head);
    }
	return 0;
}
