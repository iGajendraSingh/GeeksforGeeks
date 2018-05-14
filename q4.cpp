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
	    int sum=0;
	    for(int i=0;i<(n/2);i++){
	        sum-= 2*arr[i];
	        sum+= 2*arr[n-i-1];
	    }
	    
	    cout<<sum<<"\n";
	}
	return 0;
}
