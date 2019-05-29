/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * @input C : Integer array
 * @input n3 : Integer array's ( C ) length
 * 
 * @Output Integer
 */
int max(int x,int y,int z)
{
    int ans=x;
    if(ans<y)
     ans=y;
    if(ans<z)
     ans=z;
    return ans;
}
int min(int x,int y,int z)
{
    int ans=x;
    if(ans>y)
     ans=y;
    if(ans>z)
     ans=z;
     return ans;
}
int solve(int* A, int n1, int* B, int n2, int* C, int n3) {
    int i=0,j=0,k=0,mini=INT_MAX,m1,m2;
    while(i<n1 && j<n2 && k<n3)
    {   m1=max(A[i],B[j],C[k]);
        m2=min(A[i],B[j],C[k]);
        if(fabs(m1-m2)<mini)
         mini=fabs(m1-m2);
        if(A[i]==m2)
        {
            i++;
        }
        else if(B[j]==m2)
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return mini;
}
