//Given an input stream of n characters consisting only of small case alphabets the task is to find the 
//first non repeating character each time a character is inserted to the stream.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        char arr[n];
        int count[26]= {0};
        queue <char> q;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            
            q.push(arr[i]);
            count[arr[i] - 'a']++;
            
            while(!q.empty()){
                if(count[q.front() - 'a']>1){
                    q.pop();
                }
                else{
                    cout<<q.front()<<" ";
                    break;
                }
            }
            
            if(q.empty())
                cout<<-1<<" ";
        }
        cout<<"\n";
    }
	return 0;
}
