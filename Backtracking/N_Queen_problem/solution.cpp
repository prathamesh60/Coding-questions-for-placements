int is_safe(int i,int j,int col[],vector <string> x,int A)
{
    if(col[j]==1)
     return 0;
    int i1=i-1,j1=j+1;
    while(i1>=0 && j1<A)
    {  if(x[i1][j1]=='Q')
         return 0;
        i1--;
        j1++;
    }
   i1=i-1,j1=j-1;
   while(i1>=0 && j1>=0)
    {  if(x[i1][j1]=='Q')
         return 0;
        i1--;
        j1--;
    }
    return 1;
}
void solve(vector <vector<string> > &ans,vector <string> &x,int col[],int ind,int A)
{
    int i,j,k;
    for(i=0;i<A;i++)
    {
        if(is_safe(ind,i,col,x,A)==1)
        {
            x[ind][i]='Q';
            col[i]=1;
            if(ind==A-1)
             ans.push_back(x);
            else
             {
                 solve(ans,x,col,ind+1,A);
             }
           x[ind][i]='.';
           col[i]=0;
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   vector <vector<string> > ans;
   vector <string> x;
   int row[A],col[A];
   memset(col,0,sizeof col);
  int i,j;
  for(i=0;i<A;i++)
  {
      string s;
      for(j=0;j<A;j++)
       s.push_back('.');
      x.push_back(s);
  }
  solve(ans,x,col,0,A);
  return ans;
}
