#define li 1000000007
int Solution::chordCnt(int A) {
    long sum=3,a=0,b=1;
    
    if(A==1)
     return b;
    if(A==2)
      return 2;
    else
    {
        int i;
        int dp[A+1];
        dp[0]=1;
        dp[1]=1,dp[2]=2;
        for(i=3;i<=A;i++)
        {
            long sum=0;
            int  j=i-1,k=0;
            while(j>=0 && k<=i-1)
            {   long x=dp[j],y=dp[k];
                sum=(sum+((x*y)%li))%li;
                j--;
                k++;
            }
           dp[i]=sum;
          // cout<<dp[i]<<endl;
        }
      return dp[A];
    
    }

    
}
