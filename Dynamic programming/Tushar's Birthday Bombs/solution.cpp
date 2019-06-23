vector<int> Solution::solve(int n, vector<int> &B) {
    int min=B[0],mini,i;
    vector<int> ans;
    int index=0;
   for(i=1;i<B.size();i++)
   {
       if(min>B[i])
        { min=B[i];
          index=i;
        }
   }
    
    int num=(n/min);
    int mod=n-num*min,p=0;
    //cout<<mod<<endl;
    for(i=0;i<num;i++)
     {
           ans.push_back(index);
         //       cout<<ans[i]<<" ";
     }
    //cout<<endl;
    
    i=0,mini=B[0];
    while(mod>0 && B[i]!=min && p<num)
    {  if(i==0 || B[i]<mini)
       {
        if(B[i]-min<=mod)
        {
            int k=mod/(B[i]-min);
            int k1=mod%(B[i]-min);
            int count=k;
            while(p<num && count>=1)
            {   ans[p]=i;
                p++;
                count--;
            }
           mod=k1;
        }
         B[i]=mini;
       }
        i++;
    }
    
    return ans;
}
