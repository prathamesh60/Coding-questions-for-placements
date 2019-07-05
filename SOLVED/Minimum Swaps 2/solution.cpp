int minimumSwaps(vector<int> arr) {
     vector<pair<int,int>> a;
     int i,j,k;
     for(i=0;i<arr.size();i++)
      {
          a.push_back(make_pair(arr[i],i));
      }
     sort(a.begin(),a.end(),rule);
     int vis[arr.size()];
     int no=0,cyc;
     memset(vis,0,sizeof vis);
     for(i=0;i<a.size();i++)
      {
          if(vis[i]!=0 || a[i].second==i)
            continue;
          cyc=0;
          j=i;
          while(vis[j]!=1)
           {
               vis[j]=1;
               j=a[j].second;
               cyc++;
           }
          if(cyc>0)
           no+=(cyc-1);
      }
    return no;

}
