int no_problem(vector<vector<char> > &A,int x,int i1,int j1,int r[][9],int c[][9],int b[][9])
{  if(r[i1][x-1]==0 && c[j1][x-1]==0 && b[3*(i1/3)+(j1/3)][x-1]==0)
     return 1;
   else
     return 0;
}
int solve(vector<vector<char> > &A,int r[][9],int c[][9],int b[][9] )
{
int i1=-1,j1=-1,flag=0,i,j;
   for(i=0;i<A.size() && flag==0;i++)
   {
       for(j=0;j<A[i].size() && flag==0;j++)
       {
           if(A[i][j]=='.')
           {
               i1=i;
               j1=j;
               flag=1;
           }
       }
   }
 // cout<<i1<<" "<<j1<<endl;
   if(flag==0)
    return 1;
   for(i=1;i<=9;i++)
   {  if(no_problem(A,i,i1,j1,r,c,b)==1)
       {A[i1][j1]=48+i;
        r[i1][i-1]=1;
        c[j1][i-1]=1;
        b[3*(i1/3)+(j1/3)][i-1]=1;
        if(solve(A,r,c,b)==1)
          {
            return 1;
          }
          else
          {
            A[i1][j1]='.';
            r[i1][i-1]=0;
            c[j1][i-1]=0;
            b[3*(i1/3)+(j1/3)][i-1]=0;
          }
       }
   }
   return -1;
}   
void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   int r[9][9],c[9][9],b[9][9];
   memset(r,0,sizeof r);
   memset(c,0,sizeof c);
   memset(b,0,sizeof b);
   int i,j,k;
   for(i=0;i<A.size();i++)
   {
       for(j=0;j<A[i].size();j++)
       {
           if(A[i][j]!='.')
           {
            r[i][A[i][j]-49]=1;
            c[j][A[i][j]-49]=1;
            b[3*(i/3)+(j/3)][A[i][j]-49]=1;
           }
       }
   }
   int x=solve(A,r,c,b);
}
