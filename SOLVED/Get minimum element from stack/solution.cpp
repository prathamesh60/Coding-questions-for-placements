
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{ if(s.empty()==true)
    return -1;
  else
  return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{ 
  
  if(s.empty()==true)
    return -1;
  else if(s.top()>minEle)
   {  int k=s.top();
       s.pop();
      //printf("%d ",k);
      return k;
   }
  else
   { int k1=minEle;
     int k=s.top();
     minEle=2*minEle-k;
     //printf("%d ",minEle);
     s.pop();
     return k1;
   }
  
}
/*push element x into the stack*/
void _stack::push(int x)
{
   if(s.empty()==true)
     { s.push(x);
       minEle=x;     
     }
   else if(x>=minEle)
     { s.push(x);
     }
   else
     { s.push(2*x-minEle);
       minEle=x;     
     }
    
}
