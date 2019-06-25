int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n,m;
     n=A.size();
     m=A[0].size();
     
    int dp[n][m];
    
    memset(dp,0,sizeof dp);
    int i,j;
    for(i=n-1;i>=0;i--)
     {
         for(j=m-1;j>=0;j--)
           {
              if(i==n-1 && j==m-1)
               {
                  dp[i][j]=A[i][j];
               }
             else if(i==n-1)
              {
                 int x=dp[i][j+1];
                 dp[i][j]=min(A[i][j],A[i][j]+x);
              }
             else if(j==m-1)
              {
                 int x=dp[i+1][j];
                 dp[i][j]=min(A[i][j],A[i][j]+x);
              }
              else
              {
                  int x=max(dp[i+1][j],dp[i][j+1]);
                  dp[i][j]=min(A[i][j],A[i][j]+x);
              }
          }
     }
    /* for(i=0;i<n;i++)
      {
          
      }*/
     if(dp[0][0]>0)
       return 1;
     else
       return fabs(dp[0][0])+1;
    
    
}
