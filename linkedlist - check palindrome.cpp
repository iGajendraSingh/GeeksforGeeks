\\Given a singly linked list of integers, Your task is to complete the function isPalindrome that returns
\\true if the given list is palindrome, else returns false.
{
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

}

#include<bits/stdc++.h>
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    stack <int> stk;
    struct Node* curr = head;
    while(curr!=NULL){
        stk.push(curr->data);
        curr = curr->next;
    }
    
    curr = head;
    int flag=0;
    while(curr!=NULL){
        if(stk.top()==curr->data)
            flag=1;
        else{
            flag=0;
            break;
        }
        stk.pop();
        curr = curr->next;
    }
    
    if(flag==1)
        return true;
    else
        return false;
}
