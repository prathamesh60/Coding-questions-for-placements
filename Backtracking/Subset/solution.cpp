void print_subset(vector<int> A,vector< vector<int>>&x, vector<int>&y,int index)
{
    x.push_back(y);
    int i;
    for(i=index;i<A.size();i++)
    {
        y.push_back(A[i]);
        print_subset(A,x,y,i+1);
        y.pop_back();
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
  sort(A.begin(),A.end());
   vector< vector<int>> x;
   vector<int>y;
   int index=0;
   print_subset(A,x,y,index);
   return x;
}
