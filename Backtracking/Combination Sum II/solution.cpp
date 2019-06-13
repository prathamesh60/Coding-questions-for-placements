void solve(vector<int> A, vector <vector<int>> &ans,vector<int> &x,int B,int ind)
{   int i;
    for(i=ind;i<A.size();i++)
    {
        if(A[i]<B &&(i==0 || (A[i]!=A[i-1]) || (x[x.size()-1]==A[i] && i==ind)))
         {
             x.push_back(A[i]);
             solve(A,ans,x,B-A[i],i+1);
             x.pop_back();
         }
        else if(A[i]==B && (i==0 || (A[i]!=A[i-1]) || (x[x.size()-1]==A[i] && i==ind)) )
         {
             x.push_back(A[i]);
             ans.push_back(x);
             x.pop_back();
         }
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   vector <vector<int>> ans;
   vector<int> x;
   int index=0;
   sort(A.begin(),A.end());
   solve(A,ans,x,B,index);
   return ans;
}
