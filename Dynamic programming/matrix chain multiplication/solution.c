#include <stdio.h>
#include <limits.h>
int find(int a[],int n)
{   int i,j,k,p,min,x,y;
    int dp[n][n];
    memset(dp,0,sizeof dp);
    for(i=1;i<n;i++)
    {
        dp[i][i]=0;
    }
    
    for(i=1;i<n-1;i++)
    {  // printf("%d\n",i);
        for(j=1;j<n-i;j++)
        { k=i+j;
          min=INT_MAX;
          // printf("%d %d\n",j,k);
          for(p=k-1;p>=j;p--)
          {
             x=dp[j][p]+dp[p+1][k];
            // printf("%d\n",x);
             y=(a[j-1])*(a[p])*(a[k]);
            // printf("%d %d %d %d\n",a[j-1],a[p],a[k],y);
             if(x+y<min)
             min=x+y;
            // printf("%d\n",min);
          }
          dp[j][k]=min;
            
        }
    }
  return dp[1][n-1];  
}
int main() {
	int t,n,k,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	    scanf("%d",&n);
	    int a[n];
	    for(j=0;j<n;j++)
	    {
	        scanf("%d",&a[j]);
	    }
	   int k=find(a,n);
	   printf("%d\n",k);
	}
	return 0;
}
