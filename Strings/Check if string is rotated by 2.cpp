//Given two strings, the task is to find if a string ('a') can be obtained by rotating another string ('b') by two places.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{string a,b,c="",d="";
	    cin>>a>>b;
	    long n=b.size();
	    c=b.substr(2,n-2)+b.substr(0,2);
	    d=b.substr(n-2,2)+b.substr(0,n-2);
	 if(a==c||a==d)
	 cout<<"1"<<endl;
	 else
	 cout<<"0"<<endl;
	}
	return 0;
}
