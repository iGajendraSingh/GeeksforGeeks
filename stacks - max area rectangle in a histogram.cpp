//Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
//For simplicity, assume that all bars have same width and the width is 1 unit.
//For example, consider the following histogram with 7 bars of heights {6, 2, 5, 4, 5, 2, 6}. 
//The largest possible rectangle possible is 12
#include <bits/stdc++.h>
using namespace std;
void maxRect(int arr[], int n){
    stack <int> stk;
    int max_area = 0;
    int tp; //top of stack
    int area; //area with top element as the smallest bar
    
    int i=0;
    while(i<n){
        if(stk.empty() || arr[stk.top()]<=arr[i]){
            stk.push(i);
            i++;
        }
        
        else{
            int s = stk.top();
            stk.pop();
            area = arr[s]* ((stk.empty()) ? i : (i- stk.top()-1));
            
            if(max_area<area)
                max_area = area;
        }
    }
        
        while(!stk.empty()){
            int s = stk.top();
            stk.pop();
            area = arr[s] * ((stk.empty()) ? i : (i- stk.top()-1));
            if(max_area<area)
                max_area = area;
        }
    cout<<max_area<<"\n";
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
	    maxRect(arr,n);
	}
	return 0;
}
