bool rule(pair<int,int> x,pair<int,int> y)
{
    return (x.first<y.first);
}
int solve(int *st,int ss,int ee,int i,int j,int curr,vector<int> &ans)
{  if((ee-ss+1)-st[curr] < i)
   {
       return 0;
   }
   else if(ss==ee)
    {
        st[curr]=1;
        ans[ss]=j;
        return 1;
    }
  else
   {
       int mid=(ss+ee)/2;
       st[curr]+=1;
       int p=solve(st,ss,mid,i,j,2*curr+1,ans);
       if(p==0)
       {
           p=solve(st,mid+1,ee,i-((mid-ss+1)-st[2*curr+1]),j,2*curr+2,ans);
       }
       return p;
       
   }
    
}
vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    
    vector<int>ans;
    int i;
    for(i=0;i<A.size();i++)
     {
         ans.push_back(-1);
     }
    int p=(int)ceil(log2(A.size()));
    int x= 2*(int)pow(2,p) -1;
    int *st=(int*)calloc(x,sizeof(int));
    for(i=0;i<x;i++)
    {
        st[i]=0;
    }
    vector< pair<int,int> > h;
    for(i=0;i<A.size();i++)
    {
        h.push_back(make_pair(A[i],B[i]));
    }
    
    sort(h.begin(),h.end(),rule);
    
    for(i=0;i<h.size();i++)
    {   
        solve(st,0,A.size()-1,h[i].second+1,h[i].first,0,ans);
    }
    return ans;
}
