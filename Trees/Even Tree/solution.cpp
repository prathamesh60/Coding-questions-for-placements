int fill(int no_of_chidren[],vector<int> A[],int x)
{  // cout<<"Running "<<endl;
    if(A[x].size()==0)
     {
         no_of_chidren[x]=1;
         return 1;
     }
    int j,sum=1;
    for(j=0;j<A[x].size();j++)
     {
         int k=fill(no_of_chidren,A,A[x][j]);
         sum+=k;
     }
     no_of_chidren[x]=sum;
     return sum;

}
int find(int no_of_children[],vector<int> A[],int x)
{   cout<<x<<endl;
    int ans=0;
    int i,k;
    for(i=0;i<A[x].size();i++)
     {
         if((no_of_children[A[x][i]])%2==0)
          {
              k=find(no_of_children,A,A[x][i]);
              k++;
              ans+=k;
          }
         else
          {
             k=find(no_of_children,A,A[x][i]);
             ans+=k;
          }
    }
    return ans;
}
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
     vector<int> A[t_nodes];
     int no_of_children[t_nodes];
     memset(no_of_children,0,sizeof no_of_children);
     int n=t_nodes,i,j,k;
     for(i=0;i<t_edges;i++)
      {
          A[t_to[i]-1].push_back(t_from[i]-1);
      }
     for(i=0;i<A[0].size();i++)
      {
          cout<<A[0][i]<<" ";
      }
     cout<<endl;
     k=fill(no_of_children,A,0);
     for(i=0;i<t_nodes;i++)
      cout<<no_of_children[i]<<" ";
      cout<<endl;
     k=find(no_of_children,A,0);
     return k;

}

