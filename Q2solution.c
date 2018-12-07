#include <stdio.h>
int a[10000000];

int main() { int t,n,s,i,j,sum,p1,p2,flag;
     scanf("%d",&t);
     for(i=0;i<t;i++)
        {  scanf("%d %d",&n,&s);
            int a[n];
            for(j=0;j<n;j++)
              {  scanf("%d",&a[j]);   
              }
           // mergesort(a,0,n-1);
            p1=0,p2=0,sum=0,flag=0,j=0;
            while(j<n && flag==0)
            {  if(sum<s)
                { sum+=a[j];
                  //printf("%d\n",sum);
                  p2++;        
                }
               if(sum>s)
                 { while(sum>s)
                    { sum-=a[p1];
                      p1++;  
                    }
                  //  printf("l%d",sum);
                 }
               
               if(sum==s)
                 { flag=1;
                 } 
               j++;   
            }
          if(flag==0)
           printf("-1\n");
          else 
           printf("%d %d\n",p1+1,p2);
            
       }
     return 0;
}
