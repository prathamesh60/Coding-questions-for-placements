/*This is a function problem.You only need to complete the function given below*/
// The task is to complete this function
int getId(int M[MAX][MAX], int n)
{
    stack<int> s;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        s.push(i);
    }
   while(!s.empty())
   {
      j=s.top();
      s.pop();
      if(!s.empty())
      {
       k=s.top();
       s.pop();
       if(M[k][j]==1 && M[j][k]!=1)
        {
          s.push(j);
        }
        else if(M[j][k]==1 && M[k][j]!=1)
        {
          s.push(k);
        }
        if(s.empty())
         return -1;
      }
      
   }
 
   int flag=1;
   for(i=0;i<n;i++)
   {
       if(i==j)
       continue;
       else if(M[i][j]!=1  || M[j][i]==1)
        return -1;
   }
   return j;
}
