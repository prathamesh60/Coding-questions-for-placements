#include <bits/stdc++.h>
using namespace std;
int main() {
    int i,j,k,t;
    cin>>t;
	for(i=0;i<t;i++)
	 { int n,m;
	   cin>>n>>m;
	   int a[n][m];
	   for(j=0;j<n;j++)
	    {
	      for(k=0;k<m;k++)
	       {
	          cin>>a[j][k];
	       }
	   }
	  j=0;
	  while(j<m && a[0][j]==0)
	  { // cout<<"Run\n";
	      j++;
	  }
	  int max=m-j,maxi=0;
	   //cout<<max<<" "<<j<<" "<<m<<endl; 
	  k=1;
	  while(j>0 && k<n)
	  {  if(a[k][j-1]==1)
	      {  j=j--;
	         while(j>=0 && a[k][j]==1)
	         {   
	             j--;
	         }
	         if(max < (m-1-j))
	           {max=m-1-j;
	            maxi=k;
	           }
	        j++;
	      }
	     //cout<<j<<endl;
	     k++;
	  }
	  cout<<maxi<<endl;
	}
	return 0;
}
