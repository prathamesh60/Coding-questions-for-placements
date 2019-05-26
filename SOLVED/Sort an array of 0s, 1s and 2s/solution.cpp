#include <bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void fuc(vector<int>&a)
{
    int low=0,mid=0,high=a.size()-1;
    while(mid<=high)
    {
      if(a[mid]==0)
      {
         swap(a[mid],a[low]);
         low++;
         mid++;
      }
      else if(a[mid]==1)
      {
          mid++;
      }
      else if(a[mid]==2)
      {
          swap(a[mid],a[high]);
          high--;
      }
    }
}
int main() {
	int t,n,i,j;
	cin>>t;
	for(i=0;i<t;i++)
	{   int val;
	    cin>>n;
	    vector<int>a;
	    for(j=0;j<n;j++)
	    {
	        cin>>val;
	        a.push_back(val);
	    }
	    fuc(a);
	    for(j=0;j<a.size();j++)
	    {
	        cout<<a[j]<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}
