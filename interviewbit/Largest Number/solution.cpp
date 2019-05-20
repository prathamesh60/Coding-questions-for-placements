bool sortbyorder(int i1,int i2)
{
   string str1;
   string str2;
   int p=0,k;
   int q=0;
   while(i1)
   {
       k=i1%10;
       str1.push_back(48+k);
       i1/=10;
   }
   while(i2)
   {
       k=i2%10;
       str2.push_back(48+k);
       i2/=10;
   }
   reverse(str1.begin(), str1.end()); 
   reverse(str2.begin(), str2.end());
   string str3,str4;
   str3=str1.append(str2);
   str4=str2.append(str1);
   return (str3.compare(str4)>=0);
}
string Solution::largestNumber(const vector<int> &A) {
    string s;
    vector<int> a;
    int i,j,k,p;
    for(i=0;i<A.size();i++)
    {
        a.push_back(A[i]);
    }
   
    sort(a.begin(),a.end(),sortbyorder);
    /*for(i=0;i<a.size();i++)
    {  printf("%d ",a[i]);
        //a[i]=A[i];
    }*/
    for(i=0;i<a.size();i++)
    {
        char arr[9];
        j=a[i];
        if(j==0)
        s.push_back(48);
        k=8;
        while(j)
        { p=j%10;
          arr[k]=48+p;
          k--;
          j/=10;
        }
       j=k+1;
       while(j<=8)
       {   //printf("%c ",arr[j]);
           s.push_back(arr[j]);
           j++;
       }
    }
    if(s[0]=='0')
    {
        s.erase(s.begin()+1,s.begin()+s.size());
    }
   //printf("\n");
    return s;
    
}
