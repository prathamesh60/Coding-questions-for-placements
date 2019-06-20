typedef struct Trie_Node
{   int freq;
    char x;
    struct Trie_Node *children[26];
}Trie;
Trie* newNode(char c)
{
    Trie* nptr=(Trie*)malloc(sizeof(Trie));
    nptr->x=c;
    nptr->freq=1;
    int i;
    for(i=0;i<26;i++)
    {
        nptr->children[i]=NULL;
    }
    return nptr;
}
vector<string> Solution::prefix(vector<string> &A) {
    Trie *root=newNode('.');
    int i;
    for(i=0;i<A.size();i++)
    {
        int j;
        string str;
        str.append(A[i]);
        Trie *curr=root;
        for(j=0;j<str.size();j++)
        {
            if((curr->children[str[j]-97])==NULL)
            {
                Trie *nptr=newNode(str[j]);
                curr->children[str[j]-97]=nptr;
            }
           else
            {  // printf("Running\n");
                (curr->children[str[j]-97]->freq)++;
            }
          curr=curr->children[str[j]-97];
        }
    }
   vector<string> ans; 
   
   for(i=0;i<A.size();i++)
   {
       int j=0,flag=0;
       string str;
       Trie* curr=root;
       while(flag==0 && curr!=NULL)
       {
        char c=A[i][j];
        str.push_back(c);
        if((curr->children[c-97]!=NULL) && (curr->children[c-97]->freq)==1)
          {
              flag=1;
          }
        else
          {
              curr=curr->children[c-97];
          }
          j++;
       }
      ans.push_back(str);
       
   }
  
   return ans;
}
