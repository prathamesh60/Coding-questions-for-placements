int pal[1000][1000];
void pa(string A, vector <string>& s , vector<vector<string>>& ans ,int ind,int n)
{  int i,j;
   for(i=ind;i<n;i++)
   {  
       if(pal[ind][i]==1)
       {   
           string p;
           for(j=ind;j<=i;j++)
           {
               p.push_back(A[j]);
           }
          s.push_back(p);
          pa(A,s,ans,i+1,n);
          if(i==n-1)
          {
              ans.push_back(s);
          }
          s.pop_back();
       }
   }
}
vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    //int pal[n][n];
    memset(pal,0,sizeof pal);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        pal[i][i]=1;
    }
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
         {  k=i+j;
            if(i==1 && A[j]==A[k])
            {
               pal[j][k]=1; 
            }
           else if(pal[j+1][k-1]==1 && A[j]==A[k] )
           {
               pal[j][k]=1;
           }
            
         }
    }
    
    vector <string> s;
    vector<vector<string>> ans;
    pa(A,s,ans,0,n);
    return ans;
}
