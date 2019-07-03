int Solution::maximumGap(const vector<int> &A) {
    int n=A.size();
    int left[n],right[n];
    left[0]=0;
    int mini=0,maxi,i,j;
    for(i=1;i<n;i++)
     {
        if(A[mini]>A[i])
         {
             mini=i;
             
         }
        left[i]=mini;
         
     }
    right[n-1]=n-1;
    maxi=n-1;
    for(i=n-2;i>=0;i--)
     {
         if(A[i]>A[maxi])
          {
              maxi=i;
          }
         right[i]=maxi;
     }
     maxi=0;
     i=0,j=0;
     while(i<=j && i<n && j<n)
      {
          if(A[left[i]]<=A[right[j]])
           {
               maxi=max(maxi,j-i);
               j++;
           }
          else
           {
               i++;
           }
      }
     return maxi;
}
