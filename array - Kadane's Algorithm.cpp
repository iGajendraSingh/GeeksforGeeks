//Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.
#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(int arr[], int n){
    int max_so_far = arr[0];
    int curr_max = arr[0];
    
    for(int i=1;i<n;i++){
        curr_max = max(arr[i],curr_max + arr[i]);
        max_so_far = max(curr_max, max_so_far);
    }
    
    return max_so_far;
}
int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int result = maxSubArraySum(arr,n);
	    cout<<result<<"\n";
	}
	return 0;
}
