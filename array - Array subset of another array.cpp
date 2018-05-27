#include <bits/stdc++.h>
using namespace std;

bool check(int arr1[], int arr2[], int x, int y){
	    
	    sort(arr1,arr1+x);
	    sort(arr2,arr2+y);
	    
	    int i=0,j=0;
	    
	    if(y>x)
	        return false;
	        
	    while(i<x && j<y){
	       if(arr1[i]<arr2[j])
	            i++;
	       else if(arr1[i]==arr2[j]){
	            i++;
	            j++;
	       }
	       else
	            return 0;
	   }
	   
	   if(j<y)
	        return false;
	    else
	        return true;
	   
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int x,y;
	    cin>>x>>y;
	    int arr1[x],arr2[y];
	    for(int i=0;i<x;i++){
	        cin>>arr1[i];
	    }
	    
	    for(int i=0;i<y;i++){
	        cin>>arr2[i];
	    }
	    
	   bool ans = check(arr1,arr2,x,y);
	   if(ans==true)
	       cout<<"Yes"<<"\n";
	   else
	        cout<<"No"<<"\n";
	}
}
