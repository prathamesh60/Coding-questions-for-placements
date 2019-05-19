/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* flip(char* A, int *len1) {
    int *a=(int*)malloc(2 * sizeof(int));
    int i;
    int k=strlen(A);
    int max=INT_MIN,length=0,l=0,r=-1,sum=0,p=0;
   // printf("%d\n",max);
    for(i=0;A[i]!='\0';i++)
    { if(A[i]=='0')
       {
           sum+=1;
          // printf("%d ",sum);
       }
      else
       {
           sum+=-1;
           //printf("%d ",sum);
       }
      if(sum>max)
      {
         max=sum;
         //printf("%d\n",max);
         l=p;
         r=i;
      }
      if(sum<0)
      {
         sum=0;
         p=i+1;
      }
    
    }
    if(max<0)
    *len1=0;
    else
    {
        a[0]=l+1;
        a[1]=r+1;
        *len1=2;
    }
    
  // printf("%d %d %d\n",l,r,length);
    return a;
    
}
