#include <bits/stdc++.h>
using namespace std;

int countDrops(int arr[], int n){
    int left_max=0, right_max=0;
    int lo=0, hi=n-1, result=0;
    while(lo<=hi){
        if(arr[lo]<arr[hi]){
            if(arr[lo]>left_max)
                left_max= arr[lo];
            else
                result+= left_max-arr[lo];
            lo++;
        }
        else{
            if(arr[hi]>right_max)
                right_max= arr[hi];
            else
                result+= right_max-arr[hi];
            hi--;
        }
    }
    return result;
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    int ans = countDrops(arr,n);
	    cout<<ans<<"\n";
	}
	return 0;
}
