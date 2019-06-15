int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char,int> m;
    int i,length=0,max=0,s=0;
    for(i=0;i<A.size();i++)
    {
        if(m.find(A[i])==m.end())
        {
           length++;
           m[A[i]]=1;
           if(length>max)
            max=length;
            //e=i;
        }
       else
        {  int p;
            while(A[s]!=A[i])
            {   p=m.erase(A[s]);
                length--;
                s++;
            }
            s++;
            length=i-s+1; 
           
        }
    }
    return max;
}
