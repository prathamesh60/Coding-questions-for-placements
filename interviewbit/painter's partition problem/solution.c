/**
 * @input A : Integer
 * @input B : Integer
 * @input C : Integer array
 * @input n3 : Integer array's ( C ) length
 * 
 * @Output Integer
 */
int min(int C[],int n,int mid)
 {
     int i,j=1,sum=0;
     for(i=0;i<n;i++)
     {
        sum+=C[i];
        if(sum>mid)
        {
            sum=C[i];
            j++;
        }
     }
     return j;
 }
int paint(int A, int B, int* C, int n) {
  int sum=0,max=INT_MIN;
  int i;
  for(i=0;i<n;i++)
  {
      if(C[i]>max)
      {
          max=C[i];
      }
      sum+=C[i];
  }
  int low=max,high=sum,mid;
 // printf("low=%d high=%d \n",low,high);
  while(low<high)
  {
    mid=low+(high-low)/2;
    int req=min(C,n,mid);
    if(req<=A)
    {
        high=mid;
    }
    else
    { //  printf("ER");
        low=mid+1;
      //  printf("low= %d\n",low);
    }
    
  }
  long long int k=1;
  k=((k*low)*B)%10000003;
 // printf("%lld\n",k);
   return k;
}
