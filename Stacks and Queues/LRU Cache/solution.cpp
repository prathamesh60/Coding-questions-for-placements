/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */
list <int> q;
unordered_map<int,int> ma;
int size;
LRUCache::LRUCache(int N)
{
     size=N;
     while(q.size()!=0)
     {
         int p=q.front();
         q.pop_front();
         ma.erase(p);
     }
     
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{ //  cout<<endl;
    if(ma.find(x)==ma.end())
    {
     if(q.size()==size)
     {  int p=q.front();
        q.pop_front();
        ma.erase(p);
     }
    }
    else
    {
        q.remove(x);
        ma.erase(x);
    }
    q.push_back(x);
    ma[x]=y;
  /* list<int>::iterator it;
   for(it=q.begin();it!=q.end();it++)
   {
       cout<<*it<<" ";
   }
     cout<<endl;*/
    
}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    if(ma.find(x)!=ma.end())
    {  /*if(ma[x]==3)
        {
            cout<<"l"<<x<<" ";
        }*/
        q.remove(x);
        q.push_back(x);
        return ma[x];
    }
    else
      return -1;
}
