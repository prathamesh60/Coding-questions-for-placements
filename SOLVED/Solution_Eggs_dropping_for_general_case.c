#include<stdio.h>
#include<stdlib.h>
/*
int min(int x,int y)
{ if(x>y)
   return y;
  else
   return x;
}*/
int max(int x,int y)
{ if(x>y)
    return x;
  else
    return y;
}
int minimum_tries(int n,int k,int t,int** a)
{ if(n==0)
    {  
       return 0;
    }
  else if(a[n-1][k-1]!=0)
    {  return (a[n-1][k-1]);
    }
  else
    { int i,j,min;
      i=1;
      min=1+max(minimum_tries(i-1,k-1,t,a),minimum_tries(n-i,k,t,a));
      for(i=2;i<=n-1;i++)
        {  j=1+max(minimum_tries(i-1,k-1,t,a),minimum_tries(n-i,k,t,a));
           if(j<min) 
            min=j;
        }
       a[n-1][k-1]=min;
      return min;
    }
}
int main()
{ int n,i,j,k,t,min,p;
  scanf("%d",&t);
  for(i=0;i<t;i++)
    {  scanf("%d %d",&k,&n);
       int** a=calloc(n,sizeof(int*));
       for(j=0;j<n;j++)
        a[j]=(int*)calloc(k,sizeof(int));
        p=k;
       for(j=0;j<k;j++)
         a[0][j]=1;
       for(j=0;j<n;j++)
          a[j][0]=j+1;
        min=minimum_tries(n,k,p,a);   
        printf("%d\n",min);
    }
    
    return 0;
}
