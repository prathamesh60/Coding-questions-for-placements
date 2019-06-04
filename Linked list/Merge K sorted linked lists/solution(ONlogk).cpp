/*This is a function problem.You only need to complete the function given below*/
/*Linked list Node structure
struct Node
{
    int data;
    Node* next;
};*/ 
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node *merge(Node *a, Node *b)
{
    Node *result;
    if(a==NULL)
     result= b;
    else if(b==NULL)
     result=a;
    else
    {
        if(a->data < b->data)
        {
            result=a;
            result->next=merge(a->next,b);
        }
        else
        {
            result=b;
            result->next=merge(a,b->next);
        }
    }
    return result;
}
Node * mergeKList(Node *arr[], int N)
{  Node *result=NULL;
   //cout<<N<<endl;
    if(N==1)
    {
       result=arr[0];
    }
    else 
    {
        int count=0,j=0;
        
        Node *nptr=arr[0];
        while(count < N )
        {  if(count+1 < N)
           arr[j]=merge(arr[count],arr[count+1]);
           else
           arr[j]=arr[count];
           j++;
           count+=2; 
        }
        result=mergeKList(arr,j);
    }
    return result;
}
