/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
 #define li 1000000007
int cntBits(int* A, int n) {
    
    long long int ans=0; //return value
    int i,j,k;
   long long int count0,count1; //count of no of 0s and 1s
   for(i=0;i<32;i++)
   {  count0=0,count1=0;
       for(j=0;j<n;j++)
        {
            if(A[j]%2==1)
            {
                count1++;
            }
            else
              count0++;
           A[j]/=2;   
        }
       ans=(ans+(2*((count0*count1)%li))%li)%li;
   }
   int p=ans;
   return p;
}
