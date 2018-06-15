#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    string s1, s2;
	    cin>>s1>>s2;
	    int i=0, j=0;
	    int l = s1.length();
	    int r = s2.length();
	    while(i<l && j<r){
	        //if(i<l)
	            cout<<s1[i++];
	        //if(j<r)
	            cout<<s2[j++];
	    }
	    
	    while(i<l){
	        cout<<s1[i++];
	    }
	    
	    while(j<r){
	        cout<<s2[j++];
	    }
	    cout<<"\n";
	}
	return 0;
}
