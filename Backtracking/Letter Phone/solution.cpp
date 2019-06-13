void solve(vector<string> ma,vector<string> &ans,string &x,string A,int ind)
{
    string str;
    str.append(ma[A[ind]-48]);
    int i;
    for(i=0;i<str.size();i++)
    {
        x.push_back(str[i]);
        if(ind!=A.size()-1)
         solve(ma,ans,x,A,ind+1);
        else
         {
             ans.push_back(x);
         }
       x.pop_back();
        
    }
}
vector<string> Solution::letterCombinations(string A) {
    vector<string> ma={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string x;
    vector<string> ans;
    int ind=0;
    solve(ma,ans,x,A,ind);
    return ans;
}
