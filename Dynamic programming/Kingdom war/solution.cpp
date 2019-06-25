int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size();
    int m=A[0].size();
    int dp[n][m];
    memset(dp,0,sizeof dp);
    dp[n-1][m-1]=A[n-1][m-1];
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
                    dp[i][j]=A[i][j]+dp[i][j+1];
                 }
                else if(j==m-1)
                 {
                     dp[i][j]=A[i][j]+dp[i+1][j];
                 }
                else
                 {
                     dp[i][j]=A[i][j]+dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1];
                 }
            }
      }
     int max=INT_MIN;
     for(i=0;i<n;i++)
       {
           for(j=0;j<m;j++)
             {
                 if(dp[i][j]>max)
                  {
                      max=dp[i][j];
                  }
             }
       }
    return max;
}
