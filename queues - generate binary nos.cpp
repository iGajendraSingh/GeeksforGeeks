//Given a number n, Write a program that generates and prints all binary numbers with decimal values from 1 to n.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    queue <string> q;
	    q.push("1");
	    while(n--){
	        string s1 = q.front();
	        q.pop();
	        cout<<s1<<" ";
	        
	        string s2; 
	        s2 = s1;
	        
	        q.push(s1.append("0"));
	        q.push(s2.append("1"));
	    }
	    cout<<"\n";
	}
	return 0;
}
