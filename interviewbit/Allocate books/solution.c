/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int no(int *A,int n,int v)
{   int i,j,sum=0,nu=1;
    for(i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum>v)
        {
            sum=A[i];
            nu++; 
        }
    }
    return nu;
}
int books(int* A, int n, int B) {
    if(n<B)
     return -1;
    int low,high,sum=0,max=INT_MIN,max1,mid;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        if(A[i]>max)
         max=A[i];
    
    }
    k=n-B+1;
    for(i=0;i<k;i++)
    {
        sum+=A[i];
    }
    max1=sum,j=0;
    for(i=k;i<n;i++)
    {
        sum=sum-A[j]+A[i];
        j++;
        if(sum>max1)
        {
            max1=sum;
        }
    }
    
    low=max;
    high=max1;
   // printf("%d %d\n",low,high);
    while(low<high)
    {
        mid=low+(high-low)/2;
        k=no(A,n,mid);
        if(k<=B)
        {
            high=mid;
        }
        else
        {
            low=mid+1;
        }
    }
  return low;
    
}
