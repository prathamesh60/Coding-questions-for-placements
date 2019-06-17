vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int>ans;
    int x=B.size();
    int y=A.size();
    map<string,int> m;
    int i=0,j;
    for(i=0;i<B.size();i++)
    {
        if(m.find(B[i])==m.end())
         m[B[i]]=1;
        else
         m[B[i]]++;
    }
    int sl,s;
    sl=B[0].size();
    s=sl*x;
    for(i=0;i<=y-s;i++)
    { map<string,int> temp(m);
       j=i;
       while(j<i+s)
       {
           string k=A.substr(j,sl);
           if(temp.find(k)==temp.end())
             break;
           else
             (temp[k])--;
          j=j+sl;
       }
       auto itr=temp.begin();
       int count=0;
       while(itr!=temp.end())
       {
           if(itr->second>0)
            {count++;
              break;            
            }
           itr++;
           
       }
       if(count==0)
        ans.push_back(i);
    }
    return ans;
}
