/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int repeatedNumber(const int* A, int n1) {
    int i,flag=0,j;
   // printf("%d\n",n1);
    int sq=sqrt(n1-1);
    int range= n1/sq +1;
    int count[range];
    j=0;
    memset(count,0,sizeof count);
    for(i=0;i<n1;i++)
    {  
        count[(A[i]-1)/sq]++;
        //if(A[i]==304)
        //printf("%d %d\n",A[i],(A[i]-1)/sq);
    }
    int x=count[range-1];
    for(i=0;i<range-1;i++)
    {
        if(count[i]>sq)
        {
            x=count[i];
            break;
        }
    }
    //printf("%d %d\n",i,count[i]);
    int p=sq*i+1;
    //printf("%d ",p);
    memset(count,0,sizeof count);
    for(j=0;j<n1;j++)
    {
        if(A[j]>=p && A[j] <= sq*(i+1))
         {
             (count[A[j]-p])++;
             if(count[A[j]-p]>1)
              return A[j];
         }
    }
    
    
  
}
