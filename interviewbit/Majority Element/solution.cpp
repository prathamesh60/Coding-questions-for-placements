int Solution::majorityElement(const vector<int> &A) {
    int x=A.size();
    int maj_index=0,count=1;
    int i=0,n=A.size();
    while(i<n)
     {
         if(A[i]==A[maj_index])
          {
              count++;
          }
         else
          {
              count--;
              if(count==0)
               {
                   maj_index=i;
                   count=1;
               }
          }
         i++;
     }
    return A[maj_index];
}
