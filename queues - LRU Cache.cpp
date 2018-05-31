//The task is to design and implement methods of an LRU cache. The class has two methods get and set which are defined as follows.
//get(x)   : Gets the value of the key x if the key exists in the cache otherwise returns -1
//set(x,y) : inserts the value if the key x is not already present. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
//In the constructor of the class the size of the cache should be intitialized.
{
#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int );
 
    int get(int );
 
    void set(int , int );
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

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
unordered_map<int,int>m;
list<int>l;
int n;
LRUCache::LRUCache(int N)
{
    n = N;
    m.reserve(n);
    l.clear();
    m.clear();
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
     if(m.find(x)==m.end()){
         if(l.size()==n){
             int tmp=l.front();
             l.pop_front();
             m.erase(tmp);
             
         }
    }
    else{
            l.remove(x);
            m.erase(x);
        }
    l.push_back(x);
    m[x]=y;
}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    unordered_map<int,int>::iterator it;
     it=m.find(x);
     if(it==m.end())
          return -1;
    else{
        l.remove(x);
        l.push_back(x);
        return it->second;
    }      
}
