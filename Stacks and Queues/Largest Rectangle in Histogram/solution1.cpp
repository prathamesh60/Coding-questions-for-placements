#include <bits/stdc++.h>
using namespace std;
long max_area(int a[],int n)
{
    int i,j,k;
    stack<int> s;
    s.push(0);
    int b[n];
    b[0]=1;
    for(i=1;i<n;i++)
    {
        while((!s.empty()) && a[s.top()]>=a[i])
        {
            s.pop();
        }
        if(s.empty())
         {
            b[i]=i+1;
         }
        else
         {
            b[i]=i-s.top();
         }
         s.push(i);
      //   cout<<b[i]<<" ";
    }
   // cout<<endl;
    int c[n];
    stack<int> s1;
    s1.push(n-1);
    c[n-1]=1;
    for(i=n-2;i>=0;i--)
    {
        while((!s1.empty()) && a[s1.top()]>=a[i])
        {
            s1.pop();
        }
        if(s1.empty())
        {
            c[i]=n-i;
        }
        else
        {
            c[i]=s1.top()-i;
        }
       s1.push(i);
      // cout<<c[i]<<" ";
    }
   // cout<<endl;
   long max=0,area,t,t1,t2;
   for(i=0;i<n;i++)
   {   t=a[i];
       t1=b[i];
       t2=c[i];
       area=t*(t1+t2-1);
       if(max<area)
        max=area;
   }
   return max;
}
int main() {
   int t,i,j;
   cin>>t;
   for(i=0;i<t;i++)
   {
       int n;
       cin>>n;
       int a[n];
       for(j=0;j<n;j++)
        cin>>a[j];
       long k;
       k=max_area(a,n);
       cout<<k<<endl;
   }
	return 0;
}
