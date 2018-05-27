//Given an expression string exp, examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
//For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])
#include <bits/stdc++.h>
using namespace std;
int isMatching(char x, char y){
    if(x=='{' && y == '}')
        return 1;
    else if(x=='[' && y == ']')
        return 1;
    else if(x=='(' && y == ')')
        return 1;
    else 
        return 0;
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    string s;
	    cin>>s;
	    stack <char> stk;
	    int flag =0;
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
	            stk.push(s[i]);
	            //cout<<stk.top()<<endl;
	        }
	       else if(s[i]==')' || s[i]=='}' || s[i]==']'){
	           if(stk.empty()){
	                flag=1;
	                break;
	           }
	           if(!isMatching(stk.top(),s[i])){
	                flag=1;
	                break;
	           }
	           //cout<<stk.top()<<endl;
	           stk.pop();
	       }
	            
	    }
	    if(flag==1 || !stk.empty())
	        cout<<"not balanced"<<"\n";
	    else
	        cout<<"balanced"<<"\n";
	        
	}
	return 0;
}
