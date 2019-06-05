int Solution::largestRectangleArea(vector<int> &A) {
    stack<pair<int,int>>s1;
    stack<pair<int,int>>s2;
    vector<int>left;
    vector<int>right;
    int i=1;
    s1.push(make_pair(A[0],1));
    left.push_back(1);
    while(i<A.size())
    {
      int count=1;
      while((!s1.empty()) && A[i]<=(s1.top()).first)
      {   count=count+(s1.top()).second;  
          s1.pop();
      }
      s1.push(make_pair(A[i],count));
      left.push_back(count);
      i++;
    }
    
    s2.push(make_pair(A[A.size()-1],1));
    right.push_back(1);
    i=A.size()-2;
    while(i>=0)
    {
      int count=1;
      while((!s2.empty()) && A[i]<=(s2.top()).first)
      {  count=count+(s2.top()).second;  
          s2.pop();
      }
      s2.push(make_pair(A[i],count));
      right.push_back(count);
      i--;   
    }
    reverse(right.begin(),right.end());
   /* for(i=0;i<A.size();i++)
    {
        cout<<left[i]<<" "<<right[i]<<" "<<A[i]<<endl;
    }*/
    int max=(left[0]+right[0]-1)*A[0];
    for(i=1;i<A.size();i++)
    { if((left[i]+right[i]-1)*A[i] >max)
       {
           max=(left[i]+right[i]-1)*A[i];
       }
        
    }
    return max;
}
