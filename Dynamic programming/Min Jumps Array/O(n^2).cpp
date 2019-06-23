int Solution::jump(vector<int> &A) {
    
    int i,n=A.size(),j,k;
    int dp[n];
    memset(dp,0,sizeof dp);
    dp[0]=0;
    for(i=1;i<n;i++)
    {   int min=INT_MAX;
        for(j=i-1;j>=0;j--)
        {
            if(A[j]+j>=i  && dp[j]!=INT_MAX && dp[j]+1<min)
            {
                min=dp[j]+1;
            }
        }
        dp[i]=min;
    }
    if(dp[n-1]==INT_MAX)
     return -1;
    else
     return dp[n-1];
}
