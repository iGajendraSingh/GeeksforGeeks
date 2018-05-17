//Given an unsorted array of non-negative integers, find a continuous sub-array which adds to a given number.

#include <bits/stdc++.h>
using namespace std;

int subArr(int arr[],int n,int s){
    int curr_sum=arr[0], i, start=0;
    for(i=1;i<=n;i++){
        if(s>curr_sum && i<n)
            curr_sum+=arr[i];
        
        while(s<curr_sum){
            curr_sum-=arr[start];
            start++;
        }
        
        if(s==curr_sum && start+1==i+1){
            cout<<i<<"\n";
            return 1;
        }
        else if(s==curr_sum){
            cout<<start+1<<" "<<i+1<<"\n";
            return 1;
        }
        else if(i==n){
            cout<<-1<<"\n";
            return 0;
        }
    }
}

int main() {
    int test;
    cin>>test;
    while(test--){
        int n,s;
        cin>>n>>s;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int ans = subArr(arr,n,s);
    }
	return 0;
}
