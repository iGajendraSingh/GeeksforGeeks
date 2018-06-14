//Given a number N, you have to find nearest prime number. If there are more then one, print the smaller one.
#include<bits/stdc++.h>
using namespace std;
bool prime[1000006];
int arr[1000005];
int fun(int arr[],int l,int h,int m)
{
    if(arr[l]>=m)return arr[l];
    if(arr[h]<=m) return arr[h];
    while(l<=h)
    {
        int mid = (l+h)/2 ;
        if(arr[mid]==m) return arr[mid];
        if(arr[mid]>m && arr[mid-1]<m)
        {
            if(abs(arr[mid]-m)<abs(arr[mid-1]-m)) return arr[mid];
            return arr[mid-1];
        }
        else if(arr[mid]<m) l = mid+1 ;
        else h  = mid-1 ;
    }
    // if(abs(arr[l]-m)>abs(arr[h]-m))
    // return arr[h];
    // return arr[l];
}
int main()
 {
     
	//code
	int t;
	cin>>t;
	memset(prime,true,sizeof(prime));
	prime[0]=false;prime[1]=false ;
	for(int i=2;i*i<1000006;i++)
	{
	    if(prime[i])
	    {
	        for(int j=2*i;j<1000006;j+=i)prime[j]=false;
	    }
	}
	int k=0;
	for(int i=2;i<1000006;i++)
	if(prime[i])arr[k++]=i;
	while(t--)
	{
	    int m;
	    cin>>m;
	    int ans = fun(arr,0,k-1,m);
	    cout<<ans<<endl;
	}
	return 0;
}
