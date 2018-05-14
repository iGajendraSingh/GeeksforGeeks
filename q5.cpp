#include <bits/stdc++.h>
using namespace std;

void bitonic(int arr[], int n){
    int inc[n],dec[n],i,j;
    
    inc[0]=1;
    dec[n-1]=1;
    
    for(i=1;i<n;i++){
        if(arr[i]>arr[i-1])
            inc[i]= inc[i-1] + 1;
        else
            inc[i]=1;
    }
    
    for(j=n-2;j>=0;j--){
        if(arr[j]>arr[j+1])
            dec[j]= dec[j+1] + 1;
        else
            dec[j]=1;
    }
    
    int max = inc[0]+dec[0]-1;
    
    for(i=1;i<n;i++){
        if(inc[i]+dec[i]-1>max)
            max = inc[i]+dec[i]-1; 
    }
    
    cout<<max<<"\n";
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n,arr[200];
	    cin>>n;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    bitonic(arr,n);
	}
	return 0;
}
