//Given an array A [ ] having distinct elements, the task is to find the next greater element 
//for each element of the array in order of their appearance in the array. If no such element exists, output -1
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while (test--)
	{
	    vector <int> arr;
	    stack <int> stk;
	    int n,p;
	    cin>>n;
	    for (int i=0;i<n;i++)
	    {
	        cin>>p;
	        arr.push_back(p);
	    }
	    
	    stk.push(arr[n-1]);
	    arr[n-1]=-1;
	    for (int i=n-2;i>=0;i--)
	    {
	        while (!stk.empty() && arr[i]>stk.top())
	            stk.pop();
	       if (stk.empty())
	        {
	            stk.push(arr[i]);
	            arr[i]=-1;}
	       else
	        {
	            int r=stk.top();
	            stk.push(arr[i]);
	            arr[i]=r;
	            
	        }
	        
	    }
	    for (int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	        cout<<endl;
	}
	return 0;
}
