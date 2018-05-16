#include <bits/stdc++.h>
using namespace std;

//We will be using XOR as XOR of same elements is 0 and
// XOR of 0 with element x is x. 

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int arr[n], res=0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        res= res^arr[i];  //XOR
	    }
	    
	    cout<<res<<"\n";
	}
	return 0;
}
