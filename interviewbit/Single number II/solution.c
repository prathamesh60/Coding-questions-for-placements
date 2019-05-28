/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int singleNumber(const int* A, int n) {
    int i,result=0,j,k=1,count1;
    for(j=0;j<31;j++)
    { count1=0;
      for(i=0;i<n;i++)
      {  if((A[i] & k)!=0)
          count1++;
        
      }
      //printf("%d\n",k);
      if(count1%3!=0)
      {
         result+=k;
      }
      k*=2;
    }
    return result;
}
