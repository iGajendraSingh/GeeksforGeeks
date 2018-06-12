{

//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void swap(int *x, int *y);
 
class MinHeap
{ public:
    int *harr; 
    int capacity;
    int heap_size;
  
    MinHeap(int capacity);
 
    
    void MinHeapify(int );
 
    int parent(int i) { return (i-1)/2; }
 
  
    int left(int i) { return (2*i + 1); }
 
 
    int right(int i) { return (2*i + 2); }
 
 
    int extractMin();
 
    
    void decreaseKey(int i, int new_val);
 
   
    int getMin() ;
 
   
    void deleteKey(int i);
 
    
    void insertKey(int k);
};
//Position this line where user code will be pasted.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
     ll a;
     cin>>a;
     MinHeap h(a);
    for(ll i=0;i<a;i++)
      {
        int c;
        int  n;
        cin>>c;
        if(c==1)
            {  cin>>n;
            
               h.insertKey(n);
             }
        if(c==2)
           {  cin>>n;
              h.deleteKey(n);
	    } 
        if(c==3)
              { 
               cout<<h.extractMin()<<" ";
               }
     
      }
       cout<<endl;
    delete h.harr;
     h.harr=NULL;
       
   }
  return 0;
  }

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the class is
class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
public:
MinHeap(int cap=100) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};*/
MinHeap :: MinHeap (int cap =100){
    heap_size=0;
    capacity=cap;
    harr=new int[cap];
}

void MinHeap :: MinHeapify(int i){
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l < heap_size &&  harr[l]< harr[smallest]){
        smallest=l;
    }
    if(r < heap_size &&  harr[r]< harr[smallest]){
        smallest=r;
    }
    if(i!=smallest){
        swap(&harr[i],&harr[smallest]);
        MinHeapify(smallest);
    }
}

/* Removes element from position x in the min heap  */
void MinHeap :: deleteKey(int i)
{
    if(i>heap_size-1 || i<0){
        return;
    }
    harr[i]=INT_MIN;
    
    while(i!=0 && harr[parent(i)] > harr[i]){
        swap(&harr[parent(i)],&harr[i]);
        i=parent(i);
    }
    
    extractMin();
    
}
/* Inserts an element at position x into the min heap*/
void MinHeap ::insertKey(int k)
{
    if(heap_size == capacity){
        return;
    }
    heap_size++;
    int i=heap_size-1;
    harr[i]=k;
    while(i!=0 && harr[i]<harr[parent(i)]){
        swap(&harr[i],&harr[parent(i)]);
        i=parent(i);
    }
}

int MinHeap ::  extractMin()
{
    if(heap_size <=0){
        return -1;
    }
    if(heap_size==1){
        
        heap_size--;
        return harr[0];
    }
    
    int min=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return min;
    
}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
