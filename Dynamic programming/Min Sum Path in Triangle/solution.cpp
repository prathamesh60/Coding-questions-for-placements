int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int dp[2][n];
    dp[0][0]=A[0][0];
    int i,j;
    for(i=1;i<n;i++)
     {
        int j;
        for(j=0;j<=i;j++)
         {  
            if(j==0)
             {
                 dp[i%2][j]=A[i][j]+dp[(i+1)%2][j];
             }
            else if(j==i)
             {
                 dp[i%2][j]=A[i][j]+dp[(i+1)%2][j-1];
             }
            else 
             {
                 dp[i%2][j]=A[i][j]+min(dp[(i+1)%2][j-1],dp[(i+1)%2][j]);
             }
         }
     }
     int mini=INT_MAX;
     for(j=0;j<n;j++)
     {
         mini=min(mini,dp[(i-1)%2][j]);
     }
    return mini;
}
