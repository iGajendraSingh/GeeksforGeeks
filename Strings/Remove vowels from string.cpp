#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int test;
	cin>>test;
	string s;
	//getline(cin,s);
	cin.ignore();  
	//ignore() will flush the input stream, just like C fflush(stdin), 
	//which is great for removing the annoying new lines stored at 
	//the end of the stream
	while(test--){
	    getline(cin,s);
	    int n = s.length();
	    for(int i=0;i<n;i++){
	        char x = tolower(s[i]);
	        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
	            continue;
	        else
	            cout<<s[i];
	    }
	    cout<<"\n";
	}
	return 0;
}
