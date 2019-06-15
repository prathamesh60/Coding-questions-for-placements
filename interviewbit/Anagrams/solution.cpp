vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int p=A.size();
    int i,j,k=0;
    unordered_map<string,int>m;
    vector<vector<int>> ans;
    for(i=0;i<p;i++)
    { string str;
      str.append(A[i]);
      sort(str.begin(),str.end());
      if(m.find(str)!=m.end())
      {
          ans[m[str]].push_back(i+1);
      }
     else
     {
         m[str]=k;
         vector<int>l;
         l.push_back(i+1);
         ans.push_back(l);
         k++;
     }
    }
   
   return ans; 
}
