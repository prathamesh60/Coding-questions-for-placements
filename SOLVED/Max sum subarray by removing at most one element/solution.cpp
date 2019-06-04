/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete below method */
int maxSumSubarray(int A[], int n)
{
    int sumi[n],revsum[n];
    int sum=0,max=INT_MIN,m;
    int i=0;
    //cout<<max<<" ";
    while(i<n)
    {
        sum+=A[i];
        sumi[i]=sum;
       // cout<<sum<<endl;
        if(sum>max)
        {
            max=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
        
      //   cout<<sumi[i]<<endl;
        i++;
    }
   
    m=max;
    sum=0,max=INT_MIN;
   //  cout<<endl<<m<<endl<<endl;
     i=n-1;
    while(i>=0)
    {
        sum+=A[i];
        revsum[i]=sum;
        if(sum>max)
        {
            max=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
      
      // cout<<revsum[i]<<endl;
        i--;
    }
   // cout<<m<<endl;
    for(i=0;i<n;i++)
    {
        int p=0;
        if(i>0)
        p+=sumi[i-1];
        if(i<n-1)
        p+=revsum[i+1];
        if(p>m)
        {
            m=p;
        }
       //cout<<p<<endl;
        
    }
    return m;
}
