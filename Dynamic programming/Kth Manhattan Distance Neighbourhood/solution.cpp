void sol( vector<vector<int>> &ans)
{
    vector<vector<int>> temp;
    int i,j,max;
    int n,m;
    n=ans.size();
    for(i=0;i<n;i++)
     {   vector<int> p;
         m=ans[i].size();
         for(j=0;j<ans[i].size();j++)
           {
               max=ans[i][j];
               
               if(i-1>=0 && ans[i-1][j]>max)
                 max=ans[i-1][j];
               if(i+1<n && ans[i+1][j]>max)
                 max=ans[i+1][j];
               if(j-1>=0 && ans[i][j-1]>max)
                 max=ans[i][j-1];
               if(j+1<m && ans[i][j+1]>max)
                 max=ans[i][j+1];
               p.push_back(max);
           }
          temp.push_back(p);
     }
   for(i=0;i<n;i++)
     {
         for(j=0;j<ans[i].size();j++)
         {
             ans[i][j]=temp[i][j];
         }
     }
}
vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
       
     vector<vector<int>> ans;
     int i,j;
     int n=B.size(),m;
     for(i=0;i<n;i++)
     {
         vector<int>p;
         for(j=0;j<B[i].size();j++)
           {
               p.push_back(B[i][j]);
           }
         ans.push_back(p);
     }
    for(i=1;i<=A;i++)
    {  
        sol(ans);
    }
      return ans;
} 
