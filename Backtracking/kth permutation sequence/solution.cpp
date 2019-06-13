void solve(vector<int> &ans,int a[],int n,long p1,int n1)
{   int i;
    if(n>12)
    {
       for(i=0;i<n1;i++)
       {
           if(a[i]==0)
            break;
       }
       ans.push_back(i+1);
       a[i]=1;
       solve(ans,a,n-1,p1,n1);
    }
   else
   {   long pro=1;
       for(i=1;i<n;i++)
       {
           pro*=i;
       }
       int count=p1/pro+1;
       if(p1%pro==0)
        count-=1;
       if(count!=0)
       {
           p1=p1-(pro*(count-1));
       }
       
       int c=0;
       for(i=0;i<n1;i++)
       {
           if(a[i]==0)
           {
             c++;  
           }
          if(c==count)
           break;
       }
       a[i]=1;
      
       ans.push_back(i+1);
       if(n!=1)
       solve(ans,a,n-1,p1,n1);
       
   }
}
string Solution::getPermutation(int n, int k) {
   
   vector<int> ans;
   int a[n];
   memset(a,0,sizeof a);
   long p1=k;
   solve(ans,a,n,p1,n);
   string s;
   int i;
   for(i=0;i<ans.size();i++)
   {
       int t=ans[i];
       cout<<t;
       int rev=0,k1;
   }
  
   return s;
}
