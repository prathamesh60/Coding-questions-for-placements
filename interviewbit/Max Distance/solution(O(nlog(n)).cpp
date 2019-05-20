int Solution::maximumGap(const vector<int> &A) {
    vector< pair<int,int> > a;
    int i,j,k=1;
   // printf("%d\n",A.size());
   for(i=0;i<A.size();i++)
    {
        a.push_back(make_pair(A[i],i));
    }
   // printf("%d\n",a.size());
  
    sort(a.begin(),a.end());
   /*for(i=0;i<a.size();i++)
   {
      printf("%d %d\n",a[i].first,a[i].second);
   }*/
   //printf("\n");
   int right[a.size()],max;
    right[a.size()-1]=a[a.size()-1].second;
    max=a[a.size()-1].second;
    //printf("%d\n",max);
    for(i=a.size()-2;i>=0;i--)
    {  
        if(a[i].second > max )
        max=a[i].second;
        
      right[i]=max;
      // printf("%d\n",max);
    }
    max=-1;
   for(i=0;i<a.size();i++)
   {   
       if(right[i]-a[i].second>max)
        max=right[i]-a[i].second;
   }
   if(A.size()==0)
     return -1;
   else
     return max;

}
