int Solution::numDecodings(string A) {
     int n=A.size();
     int dp[n+1];
    int i;
    if(A[0]=='0')
     return 0; 
   if(A[n-1]=='0')
    {
        dp[n]=0;
    }
    else
    {
        dp[n]=1;
    }
    for(i=n-2;i>=0;i--)
    {
        if(A[i]=='0')
          dp[i+1]=0;
        else
        {
           if(A[i+1]=='0')
           {
               if(i==n-2)
               {
                  if(A[i]<='2')
                  {
                      dp[i+1]=1;
                  }
                  else
                  {
                      dp[i+1]=0;
                  }
               }
              else
              {
                 if(A[i]<='2')
                 {
                     dp[i+1]=dp[i+3];
                 }
                else
                {
                    dp[i+1]=0;
                }
              }
           }
          else
           {
               dp[i+1]=dp[i+2];
               if(A[i]=='1' || (A[i]=='2' && A[i+1]<='6'))
               {   if(i==n-2)
                    dp[i+1]+=1;
                   else
                   dp[i+1]+=dp[i+3];
               }
               
           }
                       
        }
      //  cout<<i+1<<" "<<dp[i+1]<<endl;
    }
    return dp[1];
}
