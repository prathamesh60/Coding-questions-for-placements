/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int coverPoints(int* A, int n1, int* B, int n2) {
   int i,j,count=0;
   for(i=1;i<n1;i++)
   {
      // min=fabs(A[i]-A[i-1],B[i]-B[i-1]);
      count =count+ max(fabs(A[i]-A[i-1]),fabs(B[i]-B[i-1]));
       
       
   }
   return count;
}
