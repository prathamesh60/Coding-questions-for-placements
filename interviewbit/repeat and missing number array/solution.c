/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 #define li 1000000007
int* repeatedNumber(const int* A, int n1, int *len1) {
   // long long int sum=0,s=1,sum2=0,s2;
    long long int diff=0,diff2=0,p,q;
    int i,j,k;
    for(i=0;i<n1;i++)
    { 
        diff=diff+(A[i]-(i+1));
        p=1,q=1;
        p=p*A[i]*A[i];
        q=q*(i+1)*(i+1);
        diff2=diff2+(p-q);
    }
    diff2=diff2/diff;
    int x=(int)(diff+diff2)/2;
    int y=(int)(diff2-diff)/2;
    
    int *a=(int*)malloc(2*sizeof(int));
    a[0]=x;
    a[1]=y;
    *len1=2;
    return a;
    
}
