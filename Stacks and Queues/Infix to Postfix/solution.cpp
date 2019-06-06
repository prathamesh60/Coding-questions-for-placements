#include <bits/stdc++.h>
using namespace std;
int prec(char a)
{
    if(a=='^')
     return 3;
    else if(a=='/' || a=='*')
      return 2;
    else if(a=='+' || a=='-')
      return 1;
    else
      return -1;
     
}
int main() {
	int t,i,j,k;
	cin>>t;
	//cout<<t<<endl;
	for(i=0;i<t;i++)
	{ //cout<<i<<endl;
	  char str[1001];
	  cin>>str;
	  string out;
	  //cout<<str<<endl;
	  stack<char>s;
	  int j=0;
	  while(str[j]!='\0')
	  {   if(str[j]=='+' || str[j]=='-' || str[j]=='*' ||  str[j]=='/' ||  str[j]=='^')
	       {  
	           while((!s.empty()) && prec(s.top()) >= prec(str[j]))
	           {  
	              out.push_back(s.top());
	              s.pop();
	           }
	         s.push(str[j]);
	       }
	       else if(str[j]=='(')
	       {
	           s.push(str[j]);
	       }
	       else if(str[j]==')')
	       {  while(s.top()!='(')
	          {
	              out.push_back(s.top());
	              s.pop();
	          }
	          s.pop();
	           
	       }
	       else
	       { // cout<<"Run\n";
	           out.push_back(str[j]);
	       }
	       
	      j++;
	  }
	  while(!s.empty())
	  {
	      out.push_back(s.top());
	      s.pop();
	  }
	  cout<<out<<endl;
	}
	return 0;
}
