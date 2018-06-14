//Given two integers ‘L’ and ‘R’, write a program that finds the count of numbers having prime number of set bits 
//in their binary representation in the range [L, R].
#include <bits/stdc++.h>
using namespace std;

int isPrime(int n){
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
	//code
	int test;
	cin>>test;
	while(test--){
	    int l,r,count=0;
	    cin>>l>>r;
	    for(int i=l;i<=r;i++){
	        int x = __builtin_popcount(i);
	        if(isPrime(x))
	            count++;
	    }
	    cout<<count<<"\n";
	}
	return 0;
}
