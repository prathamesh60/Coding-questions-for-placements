vector<int> Solution::prevSmaller(vector<int> &A) {

    stack<int> s;
    vector<int>b; 
    b.push_back(-1);
    s.push(A[0]);
    int i,j,k;
    for(i=1;i<A.size();i++)
    {
      while((!s.empty()) && A[i]<=s.top())
      {
          s.pop();
      }
      if(s.empty())
      {
          b.push_back(-1);
      }
      else
      {
          b.push_back(s.top());
      }
      s.push(A[i]);
    }
    return b;
}
