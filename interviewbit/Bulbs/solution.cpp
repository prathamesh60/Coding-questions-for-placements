int Solution::bulbs(vector<int> &A) {
    int i,j,k,count=0;
    int n=A.size();
    //int count=0;
    int right[n];
    for(i=0;i<n;i++)
     { 
         if(A[i]==1 && count%2==1)
          {
              count++;
          }
         else if(A[i]==0 && count%2==0)
          {
              count++;
          }
     }
    
    
    return count; 
}
