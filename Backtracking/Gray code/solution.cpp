void solve(int n,vector<int> &ans,int curr)
{   if(curr==n)
    {
        return;
    }
    else if(curr==0)
    {
        ans.push_back(0);
        ans.push_back(1);
        solve(n,ans,curr+1);
    }
   else 
   {
       int i;
       int p=ans.size();
       for(i=ans.size()-1;i>=0;i--)
       {
           int k=2*ans[i]+1;
           ans.push_back(k);
           
       }
      for(i=0;i<p;i++)
      {
          ans[i]=2*ans[i];
      }
      solve(n,ans,curr+1);
    }
}
vector<int> Solution::grayCode(int A) {
    vector<int>ans;
    int curr=0;
    solve(A,ans,curr);
    return ans;
}
