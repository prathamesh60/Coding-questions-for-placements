int mini(int x,int y)
{
    if(x<y)
     return x;
    else
     return y;
}
int maxi(int x,int y)
{
    if(x>y)
      return x;
    else
      return y;
}
int Solution::maxcoin(vector<int> &A) {
    
   int i,j,k;
   int n,m;
   n=A.size();
   int dp[n][n];
   int flag=1;
   for(i=1;i<=n-1;i++)
     { if(flag=1)
         {
           for(j=0;j<n-i;j++)
             {
                k=i+j;
                if(k==j+1)
                 {
                     dp[j][k]=max(A[j],A[k]);
                 }
                else
                 {
                     dp[j][k]=max(A[j]+min(dp[j+1][k-1],dp[j+2][k]),A[k]+min(dp[j][k-2],dp[j+1][k-1]));
                 }
             }
         }
       flag*=-1;
     }
    return dp[0][n-1]; 
}
