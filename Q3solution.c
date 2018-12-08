// time complexity=O(n^2)
#include <stdio.h>
int main(){	int t,n,i,j,flag,k,max;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	 { scanf("%d",&n);
	   int a[n],b[n],c[n];
	   for(j=0;j<n;j++)
	     { scanf("%d",&a[j]);
	     }
	   b[0]=-1;
	   c[0]=a[0];
	   j=1;
	   while(j<n)
	    { max=0,flag=0;
	      for(k=j-1;k>=0;k--)
	        { if(a[k]<a[j] && c[k]>max)
	           {  flag=1;
	              c[j]=c[k];
	              b[j]=k;
	              max=c[k];
	           }
	        }
	       if(flag==0)
	         { c[j]=0;
	           b[j]=-1; 
	         }
	       c[j]+=a[j]; 
	      j++;  
	    }
	   max=c[0];
	   for(j=1;j<n;j++)
	     { if(max<c[j])
	         max=c[j];
	     }
	   printf("%d\n",max);
     }
	return 0;
}
