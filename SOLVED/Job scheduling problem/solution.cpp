#include <bits/stdc++.h>
using namespace std;
bool rule(int x,int y)
{
    return (x>=y);
}
bool rule1(pair<int,int> x, pair<int,int> y)
{
    return (x.second > y.second);
}
int  find_parent(int parent[],int s)
{
    if(parent[s]==s)
     {
         return s;
     }
    else
     {
         parent[s]=find_parent(parent,parent[s]);
         return parent[s];
     }
}
void merge(int parent[],int v,int u)
{
    parent[v]=u;
}
int main() {
   
    int t,n,i,j,k,max=0;
    cin>>t;
    //cout<<t;
    for(i=0;i<t;i++)
      {
          cin>>n;
        //  cout<<n<<endl;
          int x,b[n],c[n];
          int p=0,max=0,sum=0,count=0;
          int pr[n];
         // memset(d,0,sizeof d);
          vector<pair<int,int>> v;
          for(j=0;j<n;j++)
           {
               cin>>x>>b[j]>>c[j];
               //cout<<b[j]<<" "<<c[j]<<endl;
               v.push_back(make_pair(b[j],c[j]));
               if(b[j]>max)
                {
                    max=b[j];
                }
           }
         sort(v.begin(),v.end(),rule1);
         int parent[max+1];
         for(j=0;j<=max;j++)
          {
              parent[j]=j;
          }
         for(j=0;j<v.size();j++)
           { // cout<<v[j].first<<" "<<v[j].second<<endl;
              int k=find_parent(parent,v[j].first);
              if(k > 0)
               {
                  sum+=v[j].second;
                  merge(parent,k,find_parent(parent,k-1));
                  count++;
               }
           }
           cout<<count<<" "<<sum<<endl;
         
      }
	return 0;
}
