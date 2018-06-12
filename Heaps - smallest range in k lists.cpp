//Given K sorted lists of integers of size N each, find the smallest range that includes at least one element 
//from each of the K lists. If more than one such range's are found, print the first such range found.
{
#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000
void findSmallestRange(int arr[][N], int n, int k);
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    findSmallestRange(arr, n, k);
    }   
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// you are required to complete this function 
// function should print the required range
struct minHeapNode{
    int element;  //element to be stored
    int i; //index of the list from which element is taken
    int j; //index of next element to be picked from list
};
void minHeapify(minHeapNode harr[],int i,int heap_size){
    int l = i*2 + 1;
    int r = i*2 + 2;
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        minHeapify(harr, smallest, heap_size);
}
}

void buildHeap(minHeapNode harr[], int n)
{
    int i = (n - 1)/2;
    while (i >= 0)
    {
        minHeapify(harr, i, n);
        i--;
    }
}
void findSmallestRange(int arr[][N], int n, int k)
{
      //code here
      int range = INT_MAX;
      int min = INT_MAX, max = INT_MIN;
      int start, end;
      
      minHeapNode harr[k];
      for(int i=0;i<k;i++){
          harr[i]={arr[i][0],i,1};
          
          if(harr[i].element>max)
            max = harr[i].element;
      }
      buildHeap(harr,k);
      while(1){
          minHeapNode hp = harr[0];
          min = hp.element;
          if(range>max-min+1){
              range = max-min+1;
              start = min;
              end = max;
          }
          if(hp.j<n){
              hp.element = arr[hp.i][hp.j];
              hp.j++;
              
              if(hp.element>max)
                max = hp.element;
          }
          else
            break;
          
          harr[0] = hp;
          minHeapify(harr,0,k);
      }
      cout<<start<<" "<<end<<"\n";
}
