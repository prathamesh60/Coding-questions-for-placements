typedef struct Trie_tag
{
    char x;
    struct Trie_tag *children[26];
    bool isend;
}Trie;
Trie *newNode(char c)
{
    Trie* nptr=(Trie*)malloc(sizeof(Trie));
    nptr->x=c;
    int i;
    for(i=0;i<26;i++)
    {
        nptr->children[i]=NULL;
    }
    nptr->isend=false;
  return nptr;
}
bool rule(pair<int,int> x,pair<int,int> y)
{  if(x.first==y.first)
    {
        return (x.second<y.second);
    }
    return (x.first>y.first);
}
bool search(Trie* A,string s)
{
    
    Trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->children[idx])
            return 0;
        
        curr = curr->children[idx];
    }
    return (curr && curr->isend);
}
vector<int> Solution::solve(string A, vector<string> &B) {
   
    int i=0;
    Trie *root=newNode('.');
    int coun=0;
    while(A[i]!='\0')
    {   //cout<<i<<A[i]<<endl;
        int j=i;
        Trie* curr=root;
        while(A[j]!='\0' && A[j]!='_')
        {  if(curr->children[A[j]-97]==NULL)
           {   //if(j==i)
              //  cout<<"Rnu "<<coun<<endl;
               Trie* nptr=newNode(A[j]);
               curr->children[A[j]-97]=nptr;
           }
           curr=curr->children[A[j]-97];
            
            j++;
        }
        curr->isend=true;
        if(A[j]=='_')
        {
            i=j+1;
        }
       else
       {
          i=j;
       }
       coun++;
    }
  vector<pair<int,int>> p;
   for(i=0;i<B.size();i++)
   {
       string str;
       str.append(B[i]);
       int j=0;
       int count=0;
      // cout<<str<<endl;
       while(str[j]!='\0')
       {
          int k=j;
          Trie* curr=root;
          int flag=0;
          string s;
          while(str[k]!='\0' && str[k]!='_')
          {   s.push_back(str[k]);
              k++;
          }
          if(search(root,s)==true)
           count++;
          if(str[k]=='_')
            j=k+1;
          else
            j=k;
       }
      p.push_back(make_pair(count,i));
   }
  /* for(i=0;i<p.size();i++)
   {
       cout<<p[i].first<<endl;
   }*/
   sort(p.begin(),p.end(),rule);
   vector<int> ans;
   for(i=0;i<p.size();i++)
   {   
       ans.push_back(p[i].second);
   }
   
   return ans;
}
