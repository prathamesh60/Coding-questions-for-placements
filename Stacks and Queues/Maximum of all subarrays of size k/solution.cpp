#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,i,j,k;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n>>k;
	    int a[n];
	    for(j=0;j<n;j++)
	    {
	       cin>>a[j]; 
	    }
	  deque<int> dq;
	  for(j=0;j<k;j++)
	  {
	      while((!dq.empty()) && a[dq.back()]<= a[j])
	      {
	          dq.pop_back();
	      }
	     dq.push_back(j);
	  }
	  for(j=k;j<n;j++)
	  {
	      cout<<a[dq.front()]<<" ";
	      while((!dq.empty()) && dq.front()<= j-k)
	      {
	          dq.pop_front();
	      }
	      while((!dq.empty()) && a[dq.back()]<= a[j] )
	      {
	           dq.pop_back();
	      }
	      dq.push_back(j);
	  }
	  cout<<a[dq.front()]<<endl;
	}
	return 0;
}
