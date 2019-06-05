int Solution::braces(string A) {
    stack<char> s;
    int i=0;
    while(A[i]!='\0')
    {
       if(A[i]==')')
       {
           char p=s.top();
           s.pop();
           int flag=1;
           while(p!='(')
           { 
               if(p=='+' || p=='-' || p=='*' || p=='/')
               {
                   flag=0;
               }
              p=s.top();
              s.pop();
               
           }
           if(flag==1)
            return 1;
           
       }
       else
       {
           s.push(A[i]);
       }
       i++;
    }
    return 0;
}
