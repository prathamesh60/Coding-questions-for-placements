/* Complexity=O(n)
*/
#include <stdio.h>

int main() {
    int t,n,i,j,k,flag,p,vol,max;
    scanf("%d",&t);
    for(i=0;i<t;i++)
     {  scanf("%d",&n);
        int a[n],b[n],c[n];
        for(j=0;j<n;j++) 
           { scanf("%d",&a[j]);
           }
        b[0]=a[0];
        max=a[0];
        for(j=1;j<n;j++)
          { if(a[j]<=max)
              { b[j]=max;
              }
            else
              { max=a[j];
                b[j]=a[j];  
              }
          }
         c[n-1]=a[n-1];
         max=a[n-1];
         for(j=n-2;j>=0;j--)
           {  if(a[j]<=max)
               { c[j]=max;
               }
              else
               { max=a[j];
                 c[j]=a[j];
               }
           }
          
          vol=0;
         for(j=0;j<n;j++)
           { if(b[j]>a[j] && c[j]>a[j])
               {  if(b[j]>c[j])
                    vol+=(c[j]-a[j]);
                  else
                     vol+=(b[j]-a[j]);
               }
           }
          
         printf("%d\n",vol);
        
     }
	
	return 0;
}
