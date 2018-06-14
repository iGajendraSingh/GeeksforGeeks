//Given a range L to R, the task is to find the highest occurring digit in prime numbers which lie between L and R (both inclusive). 
//If multiple digits have same highest frequency print the largest of them. If no prime number occurs between L and R, output -1.
#include <bits/stdc++.h>
using namespace std;

void sieve(bool prime[], int n){
    for(int p = 2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i= 2*p;i<=n;i+=p){
                prime[i] = false;
            }
        }
    }
}
int main() {
	int test;
	cin>>test;
	while(test--){
	    long int l,r;
	    cin>>l>>r;
	    bool prime[r+1];
	    memset(prime,true,sizeof(prime));
	    sieve(prime,r);
	    int freq[10]={0};
	    for(int i=l;i<=r;i++){
	        if(prime[i]){
	            int p = i;
	            while(p){
	            freq[p%10]++;
	            p = p/10;
	            }           
	        }
	    }
	    
	    int max = freq[0], max_index = 0;
	    for(int i=1;i<=9;i++){
	        if(freq[i]>=max){
	            max =  freq[i];
	            max_index = i;
	        }
	    }
	    if(max!=0)
	        cout<<max_index<<"\n";
	    else
	        cout<<-1<<"\n";
	}
	return 0;
}
