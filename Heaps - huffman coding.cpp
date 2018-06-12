#include <bits/stdc++.h>
using namespace std;


struct minHeapNode{
    char data;
    int freq;
    minHeapNode *left, *right;
    
    minHeapNode(char data,int freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare {
    bool operator()(minHeapNode* l, minHeapNode* r){
        return (l->freq > r->freq);
    }
};
void printCodes(struct minHeapNode *root, string s){
    
    if(root==NULL)
        return;
    if(root->data!='$')
        cout<<s<<" ";
    
    printCodes(root->left,s+"0");
    printCodes(root->right,s+"1");
    
}
void huffmanCode(string s, int freq[], int n){
    struct minHeapNode *left, *right, *top;
    
    priority_queue<minHeapNode*, vector<minHeapNode*>, compare> minHeap;
    
    for(int i=0;i<n;i++){
        minHeap.push( new minHeapNode(s[i],freq[i]));
    }
    
    while(minHeap.size()!=1){
        left = minHeap.top();
        minHeap.pop();
        
        right = minHeap.top();
        minHeap.pop();
        
        top = new minHeapNode('$',left->freq + right->freq);
        top->left = left;
        top->right = right;
        
        minHeap.push(top);
    }
    printCodes(minHeap.top(),"");
    cout<<"\n";
}

int main() {
	//code
	int test;
	cin>>test;
	while(test--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    int freq[n];
	    for(int i=0;i<n;i++){
	        cin>>freq[i];
	    }
	    huffmanCode(s,freq,n);
	}
	return 0;
}

