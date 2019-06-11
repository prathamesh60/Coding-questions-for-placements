stack<int> s;
static int mini;
MinStack::MinStack() {
    while(!s.empty())
    s.pop();
}

void MinStack::push(int x) {
    if(s.empty())
    {
        s.push(x);
        mini=x;
    }
    else
    {
        if(x>mini)
        {
            s.push(x);
        }
        else
        {   s.push(2*x-mini);
            mini=x;
        }
    }
}

void MinStack::pop() {
    if(!s.empty())
    {
        if(s.top()>mini)
        {
           s.pop();
        }
        else
        {
            mini=2*mini-s.top();
            s.pop();
        }
    }
}

int MinStack::top() {
    if(s.empty())
      return -1;
    else
    {
        if(s.top()>mini)
         return s.top();
        else
        {
            return mini;
        }
    }
}

int MinStack::getMin() {
    if(s.empty())
     return -1;
    else
     return mini;
}

