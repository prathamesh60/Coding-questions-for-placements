bool rule(vector<int> p,vector<int> q)
{
    return ( p[2]< q[2]);
}
int find_parent(int parent[],int i)
{
    if(parent[i]!=i)
     {
         parent[i]=find_parent(parent,parent[i]);
     }
    return parent[i];
}
void unite(int parent[],int rank[],int x,int y)
{
    int p1=find_parent(parent,x);
    int p2=find_parent(parent,y);
    if(rank[p1]>rank[p2])
     {
         parent[p2]=p1;
         
     }
    else if(rank[p1]<rank[p2])
     {
         parent[p1]=p2;
     }
    else
     {
         parent[p2]=p1;
         rank[p1]++;
     }
     
}
int Solution::solve(int A, vector<vector<int> > &B) {
  //  vector<int> A[n];
    int n=A;
    int parent[n];
    int rank[n];
    memset(parent,0,sizeof parent);
    memset(rank,0,sizeof rank);
    int i,x1,y1;
    for(i=0;i<n;i++)
     {
         parent[i]=i;
         rank[i]=0;
     }
    sort(B.begin(),B.end(),rule);
    int e=0;
    int cost=0;
    i=0;
    while(e<n-1 && i<B.size())
     {
        int x=B[i][0]-1;
        int y=B[i][1]-1;
        x1=find_parent(parent,x);
        y1=find_parent(parent,y);
        if(x1!=y1)
         {
             cost+=B[i][2];
             unite(parent,rank,x1,y1);
             e++;
         }
        i++;
         
     }
     return cost;
    
}
