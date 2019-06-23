int Solution::solve(const vector<int> &A) {
    unordered_map<int,int> m;
    if(A.size()<3)
     return A.size();
    int i,k,j;
    int n=A.size();
    int dp[n][n];
    memset(dp,0,sizeof dp);
    for(i=0;i<n-1;i++)
    {  
       for(j=i+1;j<n;j++)        
         {    k=2*A[i]-A[j];
              dp[i][j]=2;
              if(m.find(k)!=m.end())
              {
                  dp[i][j]=max(dp[i][j],dp[m[k]][i]+1);
              }
         } 
       m[A[i]]=i;
    }
    int max=2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {   //cout<<dp[i][j]<<" ";
            if(dp[i][j]>max)
              max=dp[i][j];
        }
       // cout<<endl;
    
    }
   return max;
}
