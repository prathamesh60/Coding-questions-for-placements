int Solution::threeSumClosest(vector<int> &A, int B) {
   sort(A.begin(),A.end());
   int i=2,min,sum=A[i]+A[i-1]+A[i-2],j,k,m;
   min=fabs(B-sum);
   for(i=0;i<A.size()-2;i++)
   {
       j=i+1,k=A.size()-1;
       while(j<k)
       {   m=A[i]+A[j]+A[k];
           if(fabs(B-m)<min)
           {
               min=fabs(B-m);
               sum=m;
           }
           if(min==0)
            return B;
           else if(m>B)
            k--;
           else
            j++;
         
       }
     
   }
   return sum; 
}
