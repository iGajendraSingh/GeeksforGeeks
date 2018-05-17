//Given an unsorted array of positive integers.
//Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles. 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int arr[n],i;
	    for(i=0;i<n;i++){
	        cin>>arr[i];
        }
        
        sort(arr,arr+n);
        int k,count=0,j;
        for(i=0;i<n-2;i++){
            //k=i+2;
            for(j=i+1;j<n;j++){
                k=j+1;
                while(k<n && arr[i]+arr[j]>arr[k])
                    k++;
                
                 count+=k-j-1;
            }
        }
        cout<<count<<"\n";
	}
}
