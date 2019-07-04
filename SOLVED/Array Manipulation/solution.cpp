#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n,m,i,j,k,l;
    cin>>n>>m;
    long *diff=new long[n];
    memset(diff,0,sizeof diff);
    for(i=0;i<m;i++)
     {
         cin>>j>>k>>l;
         diff[j-1]+=l;
         if(k!=n)
          {
              diff[k]-=l;
          }
     }
     long max=diff[0],curr=diff[0];
     
     for(i=1;i<n;i++)
     {  
         curr=curr+diff[i];

         if(curr>max)
          max=curr;
     }
    cout<<max<<endl;
}
