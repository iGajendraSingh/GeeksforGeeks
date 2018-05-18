//Find the first repeating element in an array of integers, i.e.,
//an element that occurs more than once and whose index of first occurrence is smallest.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
            cin>>arr[i];
        
        set<int> a;
        int min=-1,i;
        for(i=n-1;i>=0;i--){
            if(a.find(arr[i])!=a.end())
                min =i;
            else
                a.insert(arr[i]);
        }
        
        if(min!=-1)
            cout<<i+1<<"\n";
        else
            cout<<-1<<"\n";
	}
}
