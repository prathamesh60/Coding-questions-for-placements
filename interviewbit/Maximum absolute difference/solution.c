/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int max(int a,int b)
{
    if(a>b)
     return a;
    else
     return b;
}
int maxArr(int* A, int n1) {
    int a[n1],b[n1],max1=INT_MIN,max2=INT_MIN,min1=INT_MAX,min2=INT_MAX,i;
    for(i=0;i<n1;i++)
    {
        a[i]=A[i]+(i+1);
        b[i]=A[i]-(i+1);
        if(a[i]>max1)
        {
            max1=a[i];
        }
        if(a[i]<min1)
         {
             min1=a[i];
         }
         
        if(b[i]>max2)
        {
            max2=b[i];
        }
        if(b[i]<min2)
         {
             min2=b[i];
         }
         
    }
    
    int ans;
    ans=max(max1-min1,max2-min2);
    return ans;
}
