#include <stdio.h>
long long int find_no_of_dollars(int n,int a[])
{   long long int ans;
	if(n<=1000000)
	{
	   ans=a[n-1];
		
	}
	else
	{
		long long int k= find_no_of_dollars(n/2,a)+ find_no_of_dollars(n/3,a)+ find_no_of_dollars(n/4,a);
		if(k>n)
		{
			ans=k;
		}
	   else
	    ans=n;
	}
	return ans;
}
int main(void) {
	int a[1000000],i,j,k;
	long long int ans;
    int n;
    a[0]=1,a[1]=2,a[2]=3;
    for(i=3;i<1000000;i++)
    {
    	k=i+1;
    	if(a[k/2-1]+a[k/3-1]+a[k/4-1]>k)
    	a[i]=a[k/2-1]+a[k/3-1]+a[k/4-1];
    	else
    	a[i]=k;
    	//printf("%d ",a[i]);
    }
   while(scanf("%d",&n)>0)
   {
   ans=find_no_of_dollars(n,a);
   printf("%lld\n",ans);
   }
	return 0;
} 
