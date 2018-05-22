//Complete the removeDuplicates() function which takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list. 
//The list should only be traversed once.
//For example if the linked list is 11->11->11->21->43->43->60 then removeDuplicates() should convert the list to 11->21->43->60.
{
//Code by Shubham Joshi
#include <bits/stdc++.h>
using namespace std;
struct Node
{
int data;
Node* next;
};
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
                Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next;
};*/
Node *removeDuplicates(Node *root)
{
 // your code goes here
 struct Node* prev= root;
 struct Node* curr = prev->next;
 struct Node* temp = NULL;
 
 while(curr!=NULL){
    temp = curr->next;
    if(prev->data==curr->data){
        prev->next = curr->next;
        free(curr);
        curr = temp;
    }
    else{
        prev= prev->next;
        curr = curr->next;
    }
 }
 
 return root;
}
