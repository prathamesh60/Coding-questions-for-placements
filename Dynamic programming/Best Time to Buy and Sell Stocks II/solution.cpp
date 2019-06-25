int Solution::maxProfit(const vector<int> &A) {
    
   int s,n=A.size();
   int e;
   int i=0;
   int profit=0;
   while(i<n)
   {
       while(i<n-1 && A[i+1]<A[i])
       {
           i++;
       }
      if(i==n-1)
       {
           break;
       }
        s=i;
      i++;
      while(i<n && A[i]>=A[i-1])
       i++;
      e=i-1;
      profit+=(A[e]-A[s]);
   }
   return profit;
}
