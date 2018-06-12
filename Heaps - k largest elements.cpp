//Given an array, print k largest elements from the array.  The output elements should be printed in decreasing order.
#include <iostream>
using namespace std;

void heapify(int arr[], int i, int n){
    
    int l = 2*i +1;
    int r = 2*i +2;
    int largest = i;
    
    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}
void buildMaxHeap(int arr[], int n){
    for(int i = n/2 -1;i>=0;i--){
        heapify(arr,i,n);
    }
}

int extractMax(int arr[],int n, int k){

	for(int i=0;i<k;i++){
    int max = arr[0];
    arr[0] = arr[n-1];
    heapify(arr,0,n--);
    // return max;
    cout<<max<<" ";
	}
}
int main() {
	int test;
	cin>>test;
	while(test--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    buildMaxHeap(arr,n);
	    extractMax(arr,n,k);
	    cout<<"\n";
	}
	
	return 0;
}
