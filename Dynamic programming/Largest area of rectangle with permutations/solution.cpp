/**
 * @input A : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer
 */
int solve(int** A, int n1, int n2) {
    int hist[n1][n2];
    memset(hist,0,sizeof hist);
    int i,j,k;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(i==0)
            {
               hist[i][j]=A[i][j];
            }
           else if(A[i][j]==1 && hist[i-1][j]!=0)
            {
                hist[i][j]=hist[i-1][j]+1;
            }
           else
           {
               hist[i][j]=A[i][j];
           }
        }
        
    }
   for(i=0;i<n1;i++)
   {
       int a[n1+1];
       memset(a,0,sizeof a);
       for(j=0;j<n2;j++)
       {
           a[hist[i][j]]++;
       }
      int p=0;
      for(j=n1;j>=0;j--)
      {
          for(k=0;k<a[j];k++)
           {hist[i][p]=j;
            p++;
           }
      }
      
   }
   int max=0;
   for(i=0;i<n1;i++)
   {
       for(j=0;j<n2;j++)
       {
           if(max < (j+1)*hist[i][j])
             max=(j+1)*hist[i][j];
       }
   }
   return max;
}
