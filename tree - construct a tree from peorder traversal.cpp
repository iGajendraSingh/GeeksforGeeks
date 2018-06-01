//Given an array ‘pre[]’ that represents Preorder traversal of a binary tree where every node has either 0 or 2 children. 
//One more array ‘preLN[]’ is given which has only two possible values ‘L’ and ‘N’. 
//The value ‘L’ in ‘preLN[]’ indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates 
//that the corresponding node is non-leaf node.Your task is to complete the function constructTree(), that constructs the 
//tree from the given two arrays and return the root pointer to new binary tree formed.
{
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node* newNode (int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}
Node* constructTree(int n, int pre[], char preLN[]);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed

struct Node *constructTreeUtil (int pre[], char preLN[], int *ind_ptr, int n){
    int ind = *ind_ptr;
    if(ind==n)
        return NULL;
    
    struct Node* curr = newNode(pre[ind]);
    (*ind_ptr)++;
    if(preLN[ind]=='N'){
        curr->left = constructTreeUtil(pre, preLN, ind_ptr, n);
        curr->right = constructTreeUtil(pre, preLN, ind_ptr, n);
    }
    
    return curr;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    

    int ind_ptr = 0;
    return constructTreeUtil (pre, preLN, &ind_ptr, n);

}
