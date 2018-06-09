//Given two arrays of equal length, the task is to find if given arrays are equal or not. 
//Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) 
//of elements may be different though. Note : If there are repetitions, then counts of repeated elements must 
//also be same for two array to be equal.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
    while(test--){
        int n,flag=0;
        cin>>n;
        int arr1[n],arr2[n];
        unordered_map <int, int> m;
        for(int i= 0;i<n;i++){
            cin>>arr1[i];
            m[arr1[i]]++;
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
            if(m.find(arr2[i])==m.end()){
                flag=1;
                break;
            }
            if(m[arr2[i]]==0){
                flag=1;
                break;
            }
            
            m[arr2[i]]--;
        }
        if(flag==1)
            cout<<0<<"\n";
        else
            cout<<1<<"\n";
    }
	return 0;
}
