int Solution::jump(vector<int> &A) {
    
    int i,j,k,l,n=A.size();
    if(A.size()==1)
     return 0;
    if(A[0]==0)
     return -1;
    int maxreach=A[0];
    int step=A[0];
    int jump=1;
    for(i=1;i<n;i++)
    {  
        if(i==n-1)
        {
            return jump;
        }
       maxreach=max(maxreach,i+A[i]);
       step--;
       if(step==0)
       {
           jump++;
           if(maxreach<=i)
           {
               return -1;
           }
          step=maxreach-i;
       }
    }
}
