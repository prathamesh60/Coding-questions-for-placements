void solve(int A, vector<string> &ans,string &x,int count1,int count2)
{   
   if(count1<A)
    {
        x.push_back('(');
        solve(A,ans,x,count1+1,count2);
        x.pop_back();
        
    }
   if(count1>count2)
   {
       x.push_back(')');
       if(count2+1==A)
       {
           ans.push_back(x);
       }
       else
       solve(A,ans,x,count1,count2+1);
       x.pop_back();
   }
}
vector<string> Solution::generateParenthesis(int A) {
   vector<string> ans; 
   string x;
   int count1=0,count2=0;
   solve(A,ans,x,count1,count2);
   return ans;
}
