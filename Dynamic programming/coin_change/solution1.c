#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Complete the getWays function below.
int getWays(int n, int c_count, int* c) {
 // printf("Run");
  int table[n+1][c_count];
  int i,k;
  int j;
  for(i=0;i<c_count;i++)
   table[0][i]=1;
  for(i=1;i<n+1;i++)
   {for(j=0;j<c_count;j++)
    {
     int x=0,y=0;
     if(i>=c[j])
      {
        x=table[i-c[j]][j];
      }
     if(j>=1)
       y=table[i][j-1];
     table[i][j]=x+y;
     //printf("%d ",table[i][j]);
    }
   }
   return table[n][c_count-1]; 
}

int main()
{
    int n;
    int m;
    scanf("%d %d",&n,&m);
    //printf("%d %d",n,m);
    int *c=(int*)malloc(m*sizeof(int));
    int i;
    for(i=0;i<m;i++)
    scanf("%d",&c[i]);
    int y = getWays(n,m,c);
    printf("%d\n",y);
}
