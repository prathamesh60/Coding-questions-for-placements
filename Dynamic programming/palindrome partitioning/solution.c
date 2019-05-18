Complexity =O(n^2)

#include <stdio.h>
#include <string.h>
int find(char a[],int n)
{
    int dp[n][n];
    memset(dp,0,sizeof dp);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        dp[i][i]=1;
        
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            k=i+j;
            if(a[j]==a[k])
            { if(i==1 || dp[j+1][k-1])
              dp[j][k]=1;
             
            }
            else 
             dp[j][k]=0;
             
        }
    }
   /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
         {
             printf("%d ",dp[i][j]);
         }
         printf("\n");
    }  */
   int dp1[n];
   int min;
   dp1[0]=0;
   for(i=1;i<n;i++)
   { //min=i;
     if(dp[0][i]==1)
     {
        dp1[i]=0; 
     }
     else
     {
         min=i;
         for(j=i-1;j>=0;j--)
         {
             if(dp[j+1][i]==1 && 1+dp1[j]<min)
             min=1+dp1[j];
         }
        dp1[i]=min;
     }
   }
   return dp1[n-1];
}
int main() {
    int t,n,i,j,k;
    scanf("%d",&t);
    char a[1001];
    for(i=0;i<t;i++)
    {
       scanf("%s",a);
       n=strlen(a); 
       int k;
       k=find(a,n);
       printf("%d\n",k);
    }
	return 0;
}
