string Solution::minWindow(string A, string B) {
   string ans;
   if(A.size()>=B.size())
   {
    int patt[257]={0};
    int str[257]={0};
    int count=0,start=0,start_index=-1,min=INT_MAX;
    int i;
    for(i=0;i<B.size();i++)
    {
        patt[B[i]]++;
       // cout<<patt[B[i]];
    }
    for(i=0;i<A.size();i++)
    {
        str[A[i]]++;
        if(patt[A[i]]!=0 &&(str[A[i]]<=patt[A[i]]))
         count++;
        if(count==B.size())
        {  //cout<<"Run"<<endl;
            while((str[A[start]] > patt[A[start]]) || (patt[A[start]]==0))
            {
                if(str[A[start]]>patt[A[start]])
                  str[A[start]]--;
                start++;
            }
           if((i-start+1)<min)
           {
               min=i-start+1;
               start_index=start;
           }
        }
     // cout<<count;
    }
   // cout<<min<<endl;;
    
    if(start_index!=-1)
    {
        for(i=start_index;i<start_index+min;i++)
         ans.push_back(A[i]);
        // ans=A.substr(start_index,min);
    }
   }
    return ans;
}
