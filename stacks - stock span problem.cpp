//The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days. 
//The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
//For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
#include <bits/stdc++.h>
using namespace std;
void stockSpan(int arr[], int n){
    
    stack <int> s;
    int ans[n];
    int i;
    s.push(0);
    ans[0]=1;
    for(i=1;i<n;i++){
        while(!s.empty() && arr[s.top()]<=arr[i]){
            s.pop();
        }
        
        ans[i] = (s.empty())? (i+1) : (i-s.top());
        
        s.push(i);
    }
    
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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
	    stockSpan(arr,n);
	}
	return 0;
}
