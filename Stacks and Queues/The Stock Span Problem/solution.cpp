#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int i,j,k,t,n;
	cin>>t;
	for(i=0;i<t;i++)
	{   stack<pair<int,int>> s;
	    cin>>n;
	    int c[n];
	    for(j=0;j<n;j++)
	    {
	        cin>>c[j];
	    }
	   s.push(make_pair(c[0],1));
	   int ans[n];
	   ans[0]=1;
       for(j=1;j<n;j++)
       {   int count=1;
           while((!s.empty()) && c[j]>=(s.top()).first )
           {
             count=count+(s.top()).second;
             s.pop();
           }
           s.push(make_pair(c[j],count));
           ans[j]=count;
       }
       for(j=0;j<n;j++)
       {
           cout<<ans[j]<<" ";
       }
       cout<<endl;
	}
	return 0;
}
