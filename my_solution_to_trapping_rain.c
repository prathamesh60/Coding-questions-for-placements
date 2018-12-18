#include<stdio.h>
int main() {
    int t,n,i,j,k,flag,p,vol,max;
    scanf("%d",&t);
    for(i=0;i<t;i++)
     {  scanf("%d",&n);
        int a[n];
        for(j=0;j<n;j++) 
           { scanf("%d",&a[j]);
           }
        j=0;
        vol=0;
        while(j<n-1)
          { k=j+1;
            while(k<n && a[k]<a[j])
              { k++;
              }
            if(k==n)
             {
               max=a[j+1];
               p=j+1;
               k=j+2; 
               while(k<n)
                 { if(max<a[k])
                     {max=a[k];
                      p=k;
                     }
                   k++; 
                 }
               k=j+1;
                while(k<p)
                  { vol+=(max-a[k]);
                     k++;
                  }
                 
             }
            else
              { for(p=j+1;p<k;p++)
                  { vol+=(a[j]-a[p]);
                  }
                  
              }
            j=k;
              
          }
         printf("%d\n",vol);
        
     }
	
	return 0;
}
