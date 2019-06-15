vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>>ans;
    sort(A.begin(),A.end());
    multimap<int,pair<int,int>> m;
    int i,j,k;
   if(A.size()>0)
   {
    for(i=0;i<A.size()-1;i++)
    {
        for(j=i+1;j<A.size();j++)
        { //cout<<A[i]+A[j]<<" "<<i<<" "<<j<<endl;
           m.insert(pair<int,pair<int,int>>(A[i]+A[j],{i,j}));
           
        }
    }

   for(i=0;i<A.size()-1;i++)
   {
       for(j=i+1;j<A.size();j++)
       {   int sum=A[i]+A[j];
           auto itr1=m.lower_bound(B-sum);
           auto itr2=m.upper_bound(B-sum);
           auto it=itr1;
           while(it!=itr2)
           {
               
            if(i!=(it->second.first) && i!=(it->second.second) && j!=(it->second.first) && j!=(it->second.second) && (it->second.first)>j )
              {
                  vector<int>temp={A[i],A[j],A[it->second.first],A[it->second.second]};
                  
                  ans.push_back(temp);
              }
               
            
             it++;
           }
       }
   }
   }
   if(ans.size()>0)
   {
   sort(ans.begin(),ans.end());
   for(i=1;i<ans.size();i++)
    {
       if(ans[i][0]==ans[i-1][0] && ans[i][1]==ans[i-1][1] && ans[i][2]==ans[i-1][2] && ans[i][3]==ans[i-1][3])
         {ans.erase(ans.begin()+i);
          i--;
         }
    }
   }
   return ans;
}
