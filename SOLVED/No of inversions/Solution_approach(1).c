#include<stdio.h>
int temp[100000];
long long int merge(int a[],int mid,int low,int high)
{
    int i=low,j=mid,k=0;
    long long int inv_count=0;
    while((i<mid) && (j<=high))
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
            k++;
        }
        else 
        {
            temp[k]=a[j];
            k++;
            j++;
            inv_count+=(mid-i);

        }
    }
    if(i<mid)
    {
        while(i<mid)
        {
            temp[k]=a[i];
            i++;
            k++;
        }
    }
    else if(j<=high)
    {
        while(j<=high)
        {
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    k=0;
    for(i=low;i<=high;i++)
    {
        a[i]=temp[k];
        k++;
    }
    return inv_count;
}
long long int mergesort(int a[],int low,int high)
{ long long int inv_count=0;
  int mid;
  if(low<high)
  {
      mid=(low+high)/2;
      inv_count+=mergesort(a,low,mid);
      inv_count+=mergesort(a,mid+1,high);
      inv_count+=merge(a,mid+1,low,high);
  }
  return inv_count;
}
int main()
{ int a[100000],t,i,j,n;
  scanf("%d",&t);
  for(i=0;i<t;i++)
   { scanf("%d",&n);
     for(j=0;j<n;j++)
     {
         scanf("%d ",&a[j]);
     }
    long long int inv_count;
    inv_count=mergesort(a,0,n-1);
    printf("%lld\n",inv_count);
   }
   return 0;
}
