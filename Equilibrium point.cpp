//Given an array A your task is to tell at which position the equilibrium first occurs in the array. 
//Equilibrium position in an array is a position such that the sum of elements below it is equal to the sum of elements after it.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	int n;
	cin>>n;
	int arr[n],sum=0;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    sum+=arr[i];
	}
	int right_sum=sum,left_sum=0,i,flag=0;
	for(i=0;i<n;i++){
	    right_sum=right_sum-arr[i];
	    
	    if(right_sum==left_sum){
	        flag=1;
	        break;
	    }
	    
	    left_sum+=arr[i];
	}
	
	if(flag==1)
	    cout<<i+1<<"\n";
	else
	    cout<<-1<<"\n";
	}
	return 0;
}
