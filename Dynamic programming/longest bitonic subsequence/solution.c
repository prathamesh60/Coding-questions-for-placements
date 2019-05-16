#include <stdio.h>
int find_length(int a[],int n)
{
    int i,j,k;
    int b[n],c[n];
    b[0]=1;
    for(i=1;i<n;i++)
    {   b[i]=1;
        for(j=0;j<i;j++)
        {   
            if(a[j]<a[i])
            { if(b[j]+1>b[i])
                b[i]=b[j]+1;
            }
        }
      //  printf("%d ",b[i]);
    }
   // printf("\n");
    c[n-1]=1;
    for(i=n-2;i>=0;i--)
    {   c[i]=1;
        for(j=i+1;j<n;j++)
        { if(a[j]<a[i])
          {
              if(c[j]+1>c[i])
               c[i]=c[j]+1;
          }
        }
        //printf("%d ",c[i]);
    }
   // printf("\n");
    int sum=b[0]+c[0]-1;
    for(i=1;i<n;i++)
    {
        if(b[i]+c[i]-1>sum)
         sum=b[i]+c[i]-1;
    }
    return sum;
}
int main() {
	int t,n,i,j,k;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	    scanf("%d",&n);
	    int a[n];
	    for(j=0;j<n;j++)
	     scanf("%d",&a[j]);
	    int k=find_length(a,n);
	    printf("%d\n",k);
	}
	return 0;
}
