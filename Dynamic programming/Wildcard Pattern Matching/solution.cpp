int wildCard(string pattern,string str)
{
    int i,j,k,p=1;
    for(i=1;i<pattern.size();i++)
     {
         if(pattern[i]=='*' && pattern[i-1]=='*')
          {
              
          }
         else
          {
              pattern[p]=pattern[i];
              p++;
          }
     }
    int n1=str.size(),n2=p;
    int dp[n1+1][n2+1];
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(i=1;i<=n1;i++)
     {
         dp[i][0]=0;
     }
    int flag=1;
    for(i=1;i<=n2;i++)
     {
         if(pattern[i-1]!='*')
          {
              flag=0;
          }
         dp[0][i]=flag;
     }
    for(i=1;i<=n1;i++)
     {
         for(j=1;j<=p;j++)
          {   
              if(str[i-1]==pattern[j-1])
               {  //cout<<i<<" "<<j<<" "<<1<<endl;
                   dp[i][j]=dp[i-1][j-1];
               }
              else if(pattern[j-1]=='?')
               {  // cout<<i<<" "<<j<<" "<<2<<endl;
                   dp[i][j]=dp[i-1][j-1];
               }
              else if(pattern[j-1]=='*')
               {
                  
                   dp[i][j]=(dp[i-1][j] | dp[i][j-1]);
                    //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                   
               }
          }
     }
    /*for(i=0;i<=n1;i++)
     {
         for(j=0;j<=n2;j++)
           cout<<dp[i][j]<<" ";
         cout<<endl;
     }*/
     return dp[n1][n2];
}
