//Given a function that takes a binary string. The task is to return the longest size of contiguous substring containing only ‘1’.
{
#include<bits/stdc++.h>
using namespace std;
int maxlength(string s);
int main()
{
int t;
cin>>t;
while(t--)
{
string s;
cin>>s;
cout<<maxlength(s)<<endl;
}
return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

int maxlength( string s)
{
// your code here
    int i=0;
    int n = s.length();
    int count = 0, max_count=0;
    while(i<n){
        if(s[i]=='1'){
            count++;
        }
        else{
            count = 0;
            //i++;
        }
        if(max_count<count)
            max_count = count;
        i++;
    }
    return max_count;
}
