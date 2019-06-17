int gcd(int x,int y)
{   
    if(x>=y)
    {
        if(x%y==0)
        {
            return y;
        }
        else
        {
            return gcd(x%y,y);
        }
    }
   else
    {
        if(y%x==0)
        {
            return x;
        }
        else
        {
            return gcd(x,y%x);
        }
    }
}
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    map<pair<int,int>,int> m;
    int i,j,k,l;
    int maxi=0,maxim;
    for(i=0;i<A.size();i++)
    { maxim=0;
      for(j=0;j<A.size();j++)
      {
          if(i==j)
          continue;
          else
          {
             int num=B[j]-B[i];
             int denom=A[j]-A[i];
            
            if(num!=0 && denom!=0)
            {
              int x=gcd(fabs(num),fabs(denom));
               num=num/x;
             //maxim=0;
              denom=denom/x;
             if(num<0 && denom<0)
              {
                num=num*-1;
                denom=denom*-1;
              }
             else if(denom<0)
              {
                 num*=-1;
                 denom*=-1;
              }
            }
            else if(num==0)
             {
                denom=1;
             }
            else if(denom==0)
             {
                num=1;
             }
            
            
            if(m.find({num,denom})!=m.end())
             {
                (m[{num,denom}])++;
             }
            else
             {
                m[{num,denom}]=1;
             }
            if(m[{num,denom}]>maxim)
               maxim=m[{num,denom}];
        
          }
      }
      m.clear();
      //cout<<maxim;
      if(maxim+1>maxi)
      maxi=maxim+1;
    }
    return maxi;
}
