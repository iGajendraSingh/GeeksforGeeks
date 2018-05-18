//Given three arrays sorted in non-decreasing order, print all common elements in these arrays.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int x,y,z,flag=0;
	    cin>>x>>y>>z;
	    int a[x],b[y],c[z];
	    for(int i=0;i<x;i++)
	        cin>>a[i];
	    for(int i=0;i<y;i++)
	        cin>>b[i];
	    for(int i=0;i<z;i++)
	        cin>>c[i];
	    int i=0,j=0,k=0;
	    while(i<x && j<y && k<z){
	        if(a[i]==b[j] && b[j]==c[k]){
                cout<<a[i]<<" ";
                flag=1;
	            i++;
	            j++;
	            k++;
	        }
	        else if(a[i]<b[j])
	            i++;
	        else if(b[j]<c[k])
	            j++;
	        else
	            k++;
	    }
	    if(flag==0)
	        cout<<-1;
	    cout<<"\n";
	}
	return 0;
}
