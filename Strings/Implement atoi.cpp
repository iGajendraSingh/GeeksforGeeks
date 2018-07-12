//Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
{
 #include <bits/stdc++.h>
using namespace std;
int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
int atoi(string str)
{
    //Your code here
    int n;
    int i=0;
    int tot =0;
    int sign = 1;
    n = str.length();
    if(str[0]=='-'){
        sign = -1;
        i++;
    }
    for( ;i<n;i++){
        int x;
        if(isdigit(str[i])){
            x = str[i];
            tot = tot*10 + x - '0';
        }
        else{
            return -1;
        }
    }
    return sign*tot;
    
}
