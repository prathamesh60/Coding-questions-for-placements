#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)
     return b;
    else
     return gcd(b,a%b);
}
int find(int from,int to,int d)
{
    int curr1=from,curr2=0;
    int steps=1;
    int flag=0;
    
    while(flag==0)
     {
         int x=min(curr1,to-curr2);
         curr1-=x;
         curr2+=x;
         steps++;
         if(curr1==d || curr2==d)
          {
              flag=1;
          }
         else if(curr2==to)
          {
              steps++;
              curr2=0;
          }
         else if(curr1==0)
          {
             curr1=from;
             steps++;
          }
          
     }
     return steps;
}
int main() {
    int t,i,j,m,n,d;
    cin>>t;
    for(i=0;i<t;i++)
     {
         cin>>m>>n>>d;
         j=gcd(m,n);
         if(d==m || d==n)
          {
              cout<<1<<endl;
          }
         else if(d%j==0 && (d<n || d<m))
          {
              int ans=min(find(m,n,d),find(n,m,d));
              cout<<ans<<endl;
          }
         else
          {
              cout<<"-1"<<endl;
          }
         
     }
	return 0;
}
