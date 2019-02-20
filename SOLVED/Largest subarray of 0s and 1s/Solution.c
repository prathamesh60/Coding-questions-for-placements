int maxLen(int arr[], int n)
{ int sum[n],i,j,sumi=0,maxsum,minsum,max_size=0;
  for(i=0;i<n;i++)
    { if(arr[i]==0)
       sumi+=-1;
      else
       sumi+=1;
      sum[i]=sumi;
      if(sum[i]==0)
        max_size=i+1;
    }
   maxsum=sum[0],minsum=sum[0];
   for(i=1;i<n;i++)
     { if(sum[i]>maxsum)
          maxsum=sum[i];
       else if(sum[i]<minsum)
           minsum=sum[i];
     }
     
    int a[maxsum-minsum+1];
    for(i=0;i<maxsum-minsum+1;i++)
      a[i]=-1;
    for(i=0;i<n;i++)
     { if(a[sum[i]-minsum]==-1)
        { a[sum[i]-minsum]=i;
        }
       else
        { if((i-a[sum[i]-minsum])>max_size)
            max_size=i-a[sum[i]-minsum];
        }
    
     }
    return max_size;

}
