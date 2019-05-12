#include <stdio.h>
int find(char s1[],char s2[],int n1,int n2)
{  
    int i,j,k;
    int dp[n1][n2];
    memset(dp,0,sizeof dp);
    for(i=0;i<n1;i++)
    {
        if(s1[i]==s2[0])
        dp[i][0]=1;
    }
    for(i=0;i<n2;i++)
    {
        if(s1[0]==s2[i])
        dp[0][i]=1;
    }
    for(i=1;i<n1;i++)
     {
         for(j=1;j<n2;j++)
         {
             if(s1[i]==s2[j])
             {
                 dp[i][j]=1+dp[i-1][j-1];
             }
             else
               dp[i][j]=0;
         }
         
     }
    int max=0;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(dp[i][j]>max)
             max=dp[i][j];
        }
    }
    return max;
}
int main() {
	int t,n,m,i,j,k;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	    scanf("%d %d",&n,&m);
	    char s1[n+1],s2[m+1];
	    scanf("%s %s",s1,s2);
	    k=find(s1,s2,n,m);
	    printf("%d\n",k);
	}
	return 0;
}
