/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */
int titleToNumber(char* A) {
    int x=strlen(A);
    int i=x-1,pro=1,j,sum=0;
    while(i>=0)
    {   j=A[i]-'A'+1;
        sum=sum+(pro*j);
        pro=pro*26;
        i--;
    }
   return sum; 
}
