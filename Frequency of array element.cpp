//Given an unsorted array of N integers which can contain integers from 1 to N. 
//Some elements can be repeated multiple times and some other elements can be absent from the array. 
//Count frequency of all elements from 1 to N.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int arr[n];
	    int temp[n+1];
	    memset(temp,0,sizeof(temp));
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        temp[arr[i]]++;
	    }
	   
	    for(int i=1;i<n+1;i++){
	        cout<<temp[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
