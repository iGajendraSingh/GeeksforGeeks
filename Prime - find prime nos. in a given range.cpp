//Generate all prime numbers between two given numbers.
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    
    if(n<=1)
        return false;
    if(n<=3)
        return true;
    if(n%2==0 || n%3==0)
        return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    
    return true;
}
int main() {
	int test;
	cin>>test;
	while(test--){
	    int l,r;
	    cin>>l>>r;
	    for(int i=l;i<=r;i++){
	        if(isPrime(i))
	            cout<<i<<" "; 
	    }
	    cout<<"\n";
	}
	return 0;
}
