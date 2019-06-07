/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */
void right_place(stack<int> &s,int x)
{
    if(s.empty() || s.top()<x)
    {
        s.push(x);
    }
    else
    {
        int a=s.top();
        s.pop();
        right_place(s,x);
        s.push(a);
        
    }
}
void SortedStack :: sort()
{
  if(!s.empty())
  {
      int p=s.top();
      s.pop();
      sort();
      right_place(s,p);
  }
}
