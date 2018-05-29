//Given an expression exp of length n consisting of some brackets. 
//The task is to print the bracket numbers when the expression is being parsed.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--){
	    string s;
	    cin>>s;
	    stack <int> stk;
	    int leftbrac = 1;
	    
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='('){
	            cout<<leftbrac<<" ";
	            stk.push(leftbrac);
	            leftbrac++;
	        }
	        else if(s[i]==')'){
	            cout<<stk.top()<<" ";
	            stk.pop();
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}
