vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector <int> ans;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n=A.size();
    priority_queue< pair<int,pair<int,int>> > p;
    set< pair<int,int> > myset;
    int count=n;
    p.push(make_pair(A[n-1]+B[n-1],make_pair(n-1,n-1)));
    int i,j,k;
    for(i=0;i<count;i++)
    {
      pair<int,pair<int,int>> temp=p.top();
      p.pop();
      ans.push_back(temp.first);
      int k=temp.second.first;
      int k1=temp.second.second;
      int x=A[k]+A[k-1];
      pair<int,int> p1=make_pair(k,k1-1);
      if(myset.find(p1)==myset.end())
      {
          p.push(make_pair(A[p1.first]+B[p1.second],p1));
          myset.insert(p1);
      }
      k=temp.second.first;
      k1=temp.second.second;
      x=A[k-1]+A[k1];
      p1=make_pair(k-1,k1);
      if(myset.find(p1)==myset.end())
      {
          p.push(make_pair(A[p1.first]+B[p1.second],p1));
           myset.insert(p1);
      }
    }
    return ans;
}
