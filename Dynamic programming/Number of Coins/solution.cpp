#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,i,j,k,n,v;
	cin>>t;
	for(i=0;i<t;i++)
	 {
	     cin>>v>>n;
	     int arr[n];
	     for(j=0;j<n;j++)
	      {
	          cin>>arr[j];
	      }
	     int dp[v+1];
	     int p=INT_MAX;
	     dp[0]=0;
	     for(j=1;j<=v;j++)
	      {
	          dp[j]=p;
	      }
	     for(j=0;j<n;j++)
	      {
	          for(k=arr[j];k<=v;k++)
	            {
	                if(dp[k-arr[j]]!=p && (dp[k-arr[j]]+1 < dp[k]) ) 
	                   dp[k]=1+dp[k-arr[j]];
	            }
	      }
	    if(dp[v]!=p)
	     cout<<dp[v]<<endl;
	    else
	     cout<<-1<<endl;
	 }
	return 0;
}
