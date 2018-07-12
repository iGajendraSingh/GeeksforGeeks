//Traverse a 4x4 matrix of integers in spiral form.
#include <iostream>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int arr[4][4];
	    for(int i=0;i<4;i++){
	        for(int j=0;j<4;j++){
	            cin>>arr[i][j];
	        }
	    }
	    int i; //iterator
	    int k=0; //starting row index
	    int l=4; //ending row index
	    int m=0; //starting column index
	    int n=4; //ending column index
	    
	    while(k<l && m<n){
	        for(i=m;i<n;i++){
	            cout<<arr[k][i]<<" ";
	        }
	        k++;
	        
	        for(i=k;i<l;i++){
	            cout<<arr[i][n-1]<<" ";
	        }
	        n--;
	        
	        if(k<l){
	            for(i=n-1;i>=m;i--){
	                cout<<arr[l-1][i]<<" ";
	            }
	            l--;
	        }
	        
	        if(m<n){
	            for(i=l-1;i>=k;i--){
	                cout<<arr[i][m]<<" ";
	            }
	            m++;
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}
