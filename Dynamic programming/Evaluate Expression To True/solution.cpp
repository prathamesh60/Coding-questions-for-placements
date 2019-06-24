#define li 1003
int Solution::cnttrue(string A) {
    int n=A.size();
    int dp1[n][n];
    memset(dp1,0,sizeof dp1);
    int dp2[n][n];
    memset(dp2,0,sizeof dp2);
    int flag=1;
    int i,j,k;
    for(i=0;i<n;i++)
      {  if(flag==1)
          {
            for(j=0;j<n-i;j++)
             {
                k=i+j;
                if(j==k)
                 {
                    if(A[j]=='T')
                     {
                        dp1[j][k]=1;
                     }
                    else
                     {
                         dp2[j][k]=1;
                     }
                 }
                else 
                 {
                     long max1=0,max2=0;
                     int p=k-1;
                     while(p>j)
                      { long a=dp1[j][p-1],b=dp1[p+1][k],c=dp2[j][p-1],d=dp2[p+1][k];
                        if(A[p]=='|')
                         {
                             max1=(max1+((a*b)%li)+((a*d)%li)+((b*c)%li))%li;
                             max2=(max2+((c*d)%li))%li;
                         }
                        else if(A[p]=='&')
                         {
                             max1=(max1+((a*b)%li))%li;
                             max2=(max2+((c*d)%li)+((a*d)%li)+((b*c)%li))%li;
                         }
                        else if(A[p]=='^')
                         {
                             max1=(max1+((a*d)%li)+((b*c)%li))%li;
                             max2=(max2+((a*b)%li)+((c*d)%li))%li;
                         }
                         p-=2;   
                      }
                     dp1[j][k]=max1;
                     dp2[j][k]=max2;
                     
                 }
                // cout<<j<<" "<<k<<
                 
             }
          }
         flag*=-1;
      }
    return dp1[0][n-1];
}
