#include <bits/stdc++.h>
using namespace std;

int findCand(int arr[], int n){
    int maj_ind= 0, count =1;
    
    for(int i=1;i<n;i++){
        if(a[maj_ind]==a[i])
            count++;
        else
            count--;
        if(count==0){
            maj_ind=i;
            count=1;
        }
    }
    return arr[maj_ind];
}

void printMaj(int arr[],int n;int ind){
    int cnt=0, flag=0;
    for(int i=0;i<n;i++){
        if(ind==a[i])
            cnt++;
            
        if(cnt>n/2){
           cout<<ind<<"\n";
           flag=1;
           break;
        }
     }
     
     if(flag==0)
        cout<<"NO Majority Element"<<"\n";
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
	    
	    int ind = findCand(arr,n);
	    printMaj(arr,n,ind);
	}
	return 0;
}
