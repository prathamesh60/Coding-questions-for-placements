void com(vector <vector<int>>& ans, vector <int> &x, int A,int B,int i)
{   x.push_back(i);
    if(B>1)
     com(ans,x,A-1,B-1,i+1);
    else
    {
      ans.push_back(x);
    }
    x.pop_back();
    if(A>B)
    { com(ans,x,A-1,B,i+1);
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector <vector<int>> ans;
    vector <int> x;
    int i=1;
    if(A>=B)
     com(ans,x,A,B,i);
    return ans;
}
