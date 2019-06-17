#include <stdlib.h>
int issubset(int a[],int n,int sum)
{   int i,j;
    int subset[2][sum+1];
    for(i=0;i<=n;i++)
    { for(j=0;j<=sum;j++)
        {
            if(j==0)
             subset[i%2][j]=1;
            else if(i==0)
             subset[i%2][j]=0;
            else if(j<a[i-1])
            {
                subset[i%2][j]=subset[(i+1)%2][j];
            }
            else
               subset[i%2][j]=subset[(i+1)%2][j-a[i-1]] | subset[(i+1)%2][j];
            
        }
        
    }
    return subset[n%2][sum];
}
int main() {
   int t,n,i,j;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
       scanf("%d",&n);
       int a[n];
       int sum=0;
       for(j=0;j<n;j++)
       {
           scanf("%d",&a[j]);
           sum+=a[j];
       }
      // printf("%d",sum);
      if(sum%2!=0)
      {
          printf("NO\n");
      }
      else
      {
          int k=issubset(a,n,sum/2);
         // printf("%d",k);
          if(k==0)
          {
             printf("NO\n");
          }
          else
           printf("YES\n");
      }
       
   }
	return 0;
}
