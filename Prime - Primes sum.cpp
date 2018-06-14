//Given a number N. Find if it can be expressed as sum of two prime numbers. 
#include <bits/stdc++.h>
using namespace std;

void sieveOfEratothenes(bool prime[], int n){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(prime[i]==true){
            for(int p= 2*i;p<=n;p+=i){
                prime[p]=false;
            }
        }
    }
}
int main() {
	int test;
	cin>>test;
	while(test--){
	    long long int n;
	    int flag=0;
	    cin>>n;
	    bool prime[n+1];
	    memset(prime,true,sizeof(prime));
	    sieveOfEratothenes(prime, n);
	    for(int i=2;i<n;i++){
	        if(prime[i] && prime[n-i]){
	            cout<<"Yes"<<"\n";
	            flag = 1;
	            break;
	        }
	    }
	    if(flag==0)
	        cout<<"No"<<"\n";
	}
	return 0;
}
