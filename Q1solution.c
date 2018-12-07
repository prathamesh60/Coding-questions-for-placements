#include <stdio.h>

int main() {
	
	int t,n,i,j,max,sum;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	  { scanf("%d",&n);
	    int a[n];
	    for(j=0;j<n;j++)
	       scanf("%d",&a[j]);
	    max=a[0];
	    // first finding maximum element in array 
	    for(j=1;j<n;j++)
	     { if(max<a[j])
	          { max=a[j];
	          }
	     }
	    // if maximum element is less than zero then maximum element=max sum
	    if(max>0)
	      {  max=0,sum=0;
	        
	         for(j=0;j<n;j++)
	           { sum+=a[j];
	             if(sum<0)
	               {sum=0;
	               }
	             if(max<sum)
	              max=sum;
	              
	           }
	      }
	     
	    printf("%d\n",max);
	  }
	
	return 0;
}
