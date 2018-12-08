//time complexity=O(n)
#include <stdio.h>
int main() {
    int t,n,i,j,max,p;
    scanf("%d",&t);
    for(i=0;i<t;i++)
      { scanf("%d",&n);
        int a[n],b[n];
        for(j=0;j<n;j++)
          { scanf("%d",&a[j]);
          }
        p=1;
        b[0]=a[n-1];
        max=a[n-1];
        
        j=n-2;
        while(j>=0)
          { if(a[j]>=max)
             { max=a[j];
               b[p]=a[j];
               p++;
             }
            j--;    
          }
        for(j=p-1;j>=0;j--)
          {
            printf("%d ",b[j]);  
          }
         printf("\n");
      }
	//code
	return 0;
}
