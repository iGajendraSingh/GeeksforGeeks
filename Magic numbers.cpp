#include <bits/stdc++.h>
using namespace std;
long long int gcd (long long int a ,long long int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

long long int calgcd(long long int arr[], int n){
    long long int result=arr[0];
    for(int i=1;i<n;i++){
        result = gcd(result,arr[i]);
    }
    return result;
}

#include <bits/stdc++.h>
using namespace std;

long long int a[65];

int main() {
	long long int t,n,i;
	cin>>t;
	while(t--){
	    long long int MOD=1e9+7;
	    cin>>n;
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    long long int p=1,g;
	    for(i=0;i<n;i++)
	        p=((p*a[i])%MOD);
	    g = calgcd(a,n);
	   // cout<<p<<g;
	    long long int k= pow(p,g);
	    k=k%MOD;
	    
	    cout<<k<<"\n";
	    
	}
	return 0;
}
