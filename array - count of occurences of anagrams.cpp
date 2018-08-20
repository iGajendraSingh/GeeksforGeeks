#include <iostream>
using namespace std;
#define max 256

bool comp( char countP[], char countT[]){
    for(int i=0;i<max;i++){
        if(countP[i]!=countT[i]){
            return false;
        }
    }
    
    return true;
}
int anagram(string txt, string pat){
    int n = txt.length();
    int m = pat.length();
    int count=0;
    
    char countP[max] = {0};
    char countT[max] = {0};
    
    for(int i=0;i<m;i++){
        countP[pat[i]]++;
        countT[txt[i]]++;
    }
    
    for(int i=m;i<n;i++){
        if(comp(countP, countT))
            count++;
        
        countT[txt[i]]++;
        countT[txt[i-m]]--;
    }
    
    if(comp(countP,countT))
        count++;
        
    return count;
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    string txt, pat;
	    cin>>txt>>pat;
	    int result = anagram(txt,pat);
	    cout<<result<<"\n";
	}
	return 0;
}
