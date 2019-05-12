#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void find_index(char s[],int n,int *i1,int *j1)
{
    int i,j,k;
    int dp[n][n];
    memset(dp,0,sizeof dp);
    for(i=0;i<n;i++)
    dp[i][i]=1;
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<n-i;j++)
        {
            k=i+j;
            if(s[j]==s[k])
            {
              if(i==1)
               dp[j][k]=1;
              else if(dp[j+1][k-1]==1)
               dp[j][k]=1;
               //printf("%d %d %d\n",j,k,dp[j][k]);
            }
        }
    }
    int max=1;
    *i1=0,*j1=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(dp[i][j]==1)
            {
                if(j-i+1>max)
                {
                    max=j-i+1;
                    *i1=i,*j1=j;
                }
            }
        }
    }
}
int main() {
   int t,n,i,j,i1,j1;
   scanf("%d",&t);
   char str[10001];
   for(i=0;i<t;i++)
   {
       scanf("%s",str);
       j=strlen(str);
       find_index(str,j,&i1,&j1);
       for(j=i1;j<=j1;j++)
       printf("%c",str[j]);
       printf("\n");
   }
   return 0;
}
