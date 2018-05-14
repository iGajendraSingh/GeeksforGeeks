#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n,arr[100000];
	    cin>>n;
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    
	    int max = *max_element(arr,arr+n);
	    int min = *min_element(arr,arr+n);
	    
	    int m= max-min+1;
	    
	    if(m>n)
	        cout<<"No"<<"\n";
	    else{
	    bool visited[m];
	    memset(visited,false,m);
	   
	    for(int i=0;i<n;i++){
	        visited[arr[i]-min]=true;
	    }
	    int flag=0;
	    for(int i=0;i<m;i++){
	        if(visited[i]==false){
	            flag=1;
	            break;
	        }
	    }
	    if(flag==0)
	        cout<<"Yes"<<"\n";
	    else
	        cout<<"No"<<"\n";
	    }
	}
	return 0;
}
