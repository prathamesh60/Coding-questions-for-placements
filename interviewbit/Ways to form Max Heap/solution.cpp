//This function works for A<=100

#define li 1000000007
int comb(int n,int l)  //For calculatin nCr
{  long dp1[n+1][l+1];
  int i,j;
   memset(dp1,0,sizeof dp1);
   for(i=0;i<=n;i++)
    {
       for(j=0;j<=l;j++)
       {
          if(i>=j)
          {
              if(j==0 || j==i)
               dp1[i][j]=1;
              else
               {
                   dp1[i][j]=(dp1[i-1][j]+dp1[i-1][j-1])%li;
               }
          }
       }
    }
    int k= dp1[n][l];
    return k;
}
int Solution::solve(int A) {
  if(A<=2)
    return 1;
 
    int h=0;
    int p=A;
    int m=2;
    while(p/m>0)
    {
        h++;
        m*=2;
    }
   m/=2;
   int p1=m-1;
   int p2=A-p1;
   int l,r;
   if(p2>=m/2)
   {
       l=p1;
   }
   else
   {
       l=p1-(m/2-p2);
   }
   r=A-1-l;
   int c=comb(A-1,l);
   long ans=1;
   ans=c;
   ans=(ans*solve(l))%li;
   ans=(ans*solve(r))%li;
   p=ans;
   return p;
   
    
    
}
