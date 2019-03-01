#include <stdio.h>
int search(int b[],int p,int x)
{ int low=0,high=p-1,mid,flag,t;
  flag=0,t=0;    
  while(low <= high && flag==0 )
   { mid=(low+high)/2;
     if(b[mid]<x && b[mid+1]>x)  
       {
           flag=1;
       }
     else if(b[mid]>x)
       { high=mid-1;
       }
     else if(b[mid]<x)
       { low=mid+1;
       }
     else if(b[mid]==x)
       { flag=1;
         t=-1;
       }
   }
  if(t==-1)
   return t;
  else
    return mid+1;
    
}
int main() {
    int t,n,i,j,k,p,l;
    scanf("%d",&t);
    for(i=0;i<t;i++)
     { scanf("%d",&n);
       int a[n];
       for(j=0;j<n;j++)
        { scanf("%d",&a[j]); 
        }
      /* for(j=0;j<n;j++)
        { printf("%d ",a[j]); 
        }*/
       int b[n];
       b[0]=a[0];    
       k=1;
      for(j=1;j<n;j++)
        { if(b[0]>a[j])
             { b[0]=a[j];
             }
          else if(b[k-1]<a[j])
             { 
                b[k]=a[j];
                k++; 
             }
          else
             { l=search(b,k,a[j]);
              
               if(l!=-1)
                 {
                   b[l]=a[j];
                 }
               
             }
        }
        printf("%d\n",k);
     }
	return 0;
}
