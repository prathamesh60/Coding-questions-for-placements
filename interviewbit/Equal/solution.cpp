vector<int> Solution::equal(vector<int> &A) {
  map<int,pair<int,int>> m;
  vector<int> ans;
  if(A.size()>0)
  {
      int i,j,k;
      for(i=1;i<A.size();i++)
      {
          for(j=0;j<i;j++)
          {
             k=A[i]+A[j];
             if(m.find(k)!=m.end())
             {
                 if((m[k].first < j) && (m[k].second!=i) && (m[k].second!=j))
                 {   //vector<int> ans;
                    if(ans.size()==0)
                    {
                     ans.push_back(m[k].first);
                     ans.push_back(m[k].second);
                     ans.push_back(j);
                     ans.push_back(i);
                     //ans2.push_back(ans);
                    }
                   else 
                   {
                       if((m[k].first<ans[0])||(m[k].first==ans[0] &&m[k].second<ans[1]) || (m[k].first==ans[0] && m[k].second==ans[1] && j<ans[2]) ||(m[k].first==ans[0] && m[k].second==ans[1] && j==ans[2] && i<ans[3]))
                         {
                             ans[0]=m[k].first;
                             ans[1]=m[k].second;
                             ans[2]=j;
                             ans[3]=i;
                         }
                       
                   }
                     
                 }
             }
             else
             {
                 m[k]={j,i};
             }
          }
      }
    
     
   
  }
  return ans;
}
