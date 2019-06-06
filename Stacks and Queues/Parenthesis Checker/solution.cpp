#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	int i;
	for(i=0;i<t;i++)
	{   char str[100001];
	
	    cin>>str;
	    stack<int>s;
	    int j=0;
	    int flag=1;
	    while(str[j]!='\0' && flag==1)
	    {
	        if(str[j]=='(' || str[j]=='[' || str[j]=='{')
	        {
	            s.push(str[j]);
	        }
	        else
	        {   char c;
	            if(str[j]==')')
	             c='(';
	            else if(str[j]=='}')
	             c='{';
	            else
	             c='[';
	            if((s.empty()) || s.top()!=c)
	            {
	               flag=0;   
	            }
	            else
	              s.pop();
	        }
	        j++;
	    }
	    if(!s.empty())
	     flag=0;
	    if(flag==0)
	    {
	        cout<<"not balanced\n";
	    }
	    else
	    {
	        cout<<"balanced\n";
	    }
	}
	
	return 0;
}
