string Solution::fractionToDecimal(int A, int B) {
    string s;
    long A1=A;
    long B1=B;
    int n=0;
    if(A<0)
    { //printf("Runn\n");
      A1=A1*-1;
     // cout<<A1<<endl;
       if(B<=0)
       {
           B1=B1*-1;
       }
       else
       {
          n=1;
          s.push_back('-');
       }
    }
    else
    {
        if(B<0)
        {  if(A!=0)
             s.push_back('-');
            B1=B1*-1;
            n=1;
        }
    }
    long q=A1/B1;
    long r=A1%B1;
   if(q==0)
    {
        s.push_back(48);
    }
    while(q)
    {
        s.push_back(48+(q%10));
        q/=10;
    }
    if(n==0)
    reverse(s.begin(),s.end());
    else
     reverse(s.begin()+1,s.end());
    if(r!=0)
    {
        s.push_back('.');
        string temp;
        int flag=0;
        //int r=0;
        int p=1;
       
        unordered_map<int,int> h;
         h[r]=0;
        while(flag==0)
        {
            r=r*10;
            q=r/B1;
            r=r%B1;
           if(r==0)
            { temp.push_back(48+q);
              s.append(temp);
              flag=1;
            }
           else if(h.find(r)!=h.end())
            {  int i=0;
               temp.push_back(48+q);
                while(i<h[r])
                {
                    s.push_back(temp[i]);
                    i++;
                }
               s.push_back('(');
               while(i<temp.size())
               {
                    s.push_back(temp[i]);
                    i++;
               }
               s.push_back(')');
               flag=1;
            }
          else
          {
              h[r]=p;
              temp.push_back(48+q);
          }
          p++;
        }
    }
    
    return s;
}
