//There are given n ropes of different lengths, we need to connect these ropes into one rope. 
//The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.
#include <bits/stdc++.h>
using namespace std;

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
	    
	    priority_queue < int, vector<int>, greater<int> > pq(arr,arr+n);
	    
	    int result = 0,x,y;
	    while(pq.size()>1){
	        x = pq.top();
	        pq.pop();
	        y = pq.top();
	        pq.pop();
	        
	        result = result +x+y;
	        pq.push(x+y);
	    }
	    cout<<result<<"\n";
	}
	cout<<"\n";
	return 0;
}
