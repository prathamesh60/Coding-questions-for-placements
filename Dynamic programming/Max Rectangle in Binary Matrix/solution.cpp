int max_area(int a[],int n)
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
   int max=0,area,t,t1,t2;
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
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int x=A.size();
    int y=A[0].size();
    int arr[y];
    memset(arr,0,sizeof arr);
    int i,j,k;
    int maxi=INT_MIN;
    for(i=0;i<x;i++)
      {  
          for(j=0;j<y;j++)
            {
                if(A[i][j]==1)
                 {
                     arr[j]+=1;
                 }
                else
                 {
                     arr[j]=0;
                 }
                
            }
          int area=max_area(arr,y);
          maxi=max(maxi,area);
      }
    return maxi;
}
