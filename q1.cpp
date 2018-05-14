#include <bits/stdc++.h>
using namespace std;

bool check(int arr[], int n ){
	    int max= *max_element(arr,arr+n);
	    int min = *min_element(arr,arr+n);
	    if(n==max-min+1){
	        for(int i=0;i<n;i++){
	            int j;
	            if(arr[i]<0)
	                j= -arr[i]-min;
	            else
	                j= arr[i]-min;
	         
	            if(arr[j]<0)
	                return false;
	
	            arr[j]=-arr[j];
	        }
	        return true;
	    }
	    else
	        return false;
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
	    bool value= check(arr,n);
	    if(value==true)
	        cout<<"Yes"<<"\n";
	    else
	        cout<<"No"<<"\n";
	}
}
	
