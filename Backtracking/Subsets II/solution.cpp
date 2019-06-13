void subs(vector<int> A,vector<vector<int> >& ans, vector<int>& x,int ind)
{   int i;
    ans.push_back(x);
    for(i=ind;i<A.size();i++)
    {  if(i==0 || (A[i]!=A[i-1]) ||(x[x.size()-1]==A[i] && i==ind))
        {
          x.push_back(A[i]);
          subs(A,ans,x,i+1);
          x.pop_back();
        }
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int> > ans;
    vector<int> x;
    int ind=0;
    subs(A,ans,x,ind);
    return ans;
}
