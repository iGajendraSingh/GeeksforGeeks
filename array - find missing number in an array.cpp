//Given an array of size n-1 and given that there are numbers from 1 to n with one missing, the missing number is to be found.
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int arr[n-1];
	    for(int i=0;i<n-1;i++)
	        cin>>arr[i];
	    int x = 1;
	    int y = arr[0];
	    int i;
	    for(i=1;i<n-1;i++){
	        y=y^arr[i];
	    }
	    for(i=2;i<=n;i++){
	        x = x^i;
	    }
	    int result  = x^y;
	    cout<<result<<"\n";
	}
	return 0;
}
