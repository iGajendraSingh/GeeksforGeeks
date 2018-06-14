//Your task is to calculate sum  of primes present as digits of given number N.
#include <iostream>
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
	    int n;
	    cin>>n;
	    int count=0;
	    while(n!=0){
	        int x;
	        x = n%10;
	        if(isPrime(x))
	            count+=x;
	        n = n/10;
	    }
	    cout<<count<<"\n";
	}
	return 0;
}
