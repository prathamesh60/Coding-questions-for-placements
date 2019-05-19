/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* maxset(int* A, int n1, int *len1) {
    int i,j;
    i=0;
    while(i<n1 && A[i]<0)
    i++;
    if(i==n1)
    *len1=0;
   // printf("%d\n",i);
    int size=0,s,e;
    long long int sum,sum1=-1;
    while(i<n1)
    {  //max=1;
       j=i+1;
       sum=A[i];
       while(j<n1 && A[j]>=0)
      {   sum+=A[j];
          j++;
      
      }
       if( (sum>sum1)|| ((j-i > size) && sum==sum1))
       {
           size=j-i;
           s=i;
           e=j-1;
           sum1=sum;
       }
       while(j<n1 && A[j]<0)
       j++;
       i=j;
        
    }
   // printf("%d %d %d\n",s,e,size);
   *len1=size;
   //printf("%d %d %d\n",s,e,size);
   
   int *a=(int*)malloc(size * sizeof(int));
   if(size>0)
   { int p=0;
    for(i=s;i<=e;i++)
    {
        a[p]=A[i];
        p++;
    }
   }
   return a;
}
