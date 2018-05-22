// C program to find n'th Node in linked list
//Given a singly linked list, find middle of the linked list. 
//For example, if given linked list is 1->2->3->4->5 then output should be 3. 
//If there are even nodes, then there would be two middle nodes, we need to print second middle element. 
//For example, if given linked list is 1->2->3->4->5->6 then output should be 4.

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
/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);
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
    printf("%d
", getMiddle(head));
    }
    return 0;
}

/* Link list Node 
struct Node {
    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
    if(head==NULL)
        return -1;
    
    struct Node* mid = head;
    struct Node* temp = head;
    
    while(temp!=NULL && temp->next!=NULL){
        temp= temp->next->next;
        mid = mid -> next;
    }
    
    return mid->data;
}
