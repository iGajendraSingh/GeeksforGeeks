#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n,arr[10000];
	    cin>>n;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    sort(arr,arr+n);
	    int i= 0, j= n-1;
	    
	    while(i<j){
	        cout<<arr[j--]<<" ";
	        cout<<arr[i++]<<" ";
	    }
	    
	    if(n%2!=0){
	        cout<<arr[j];
	    }
	    
	    cout<<endl;
	}
	return 0;
}
