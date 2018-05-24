Given a singly linked list: A0→A1→…→An-1→An,
reorder it to: A0→An→A1→An-1→A2→An-2→…
Given 1->2->3->4->5 its reorder is 1->5->2->4->3.
It is recommended do this in-place without altering the nodes' values.
{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
 void reorderList(struct Node* head) ;
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("
");
}
void freeList(struct Node *head)
{
	struct Node* temp;
    while(head != NULL)
    {
        
        temp=head;
        head = head->next;
        free(temp);
    }
  
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* temp,*head;
	    cin>>n;
	    cin>>x;
	    head=newNode(x);
	    temp=head;
	    for(i=0;i<n-1;i++)
	    {
			cin>>x;
			temp->next=newNode(x);
			temp=temp->next;
			}
	   
		reorderList(head);
	    printList(head);
freeList(head);
   }
   return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Following is the Linked list node structure */
/*struct Node
{
    int data;
    Node* next;
};*/

struct Node* reverse(Node* head){
    
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    
    if(head==NULL || head->next==NULL)
        return head;
    
    while(curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    }
    head = prev;
    //printList(head);
    //cout<<"\n";
    return head;
    
}
void reorderList(Node* head) 
{
    // Your code here
    //1st split the linkedlist into 2 halves
    
    struct Node *x, *y;
    x = head;
    y = head->next;
    
    while(y!=NULL && y->next!=NULL){
        x = x->next;
        y = y->next->next;
    }
    // node x is the middle element
    
    struct Node *temp = x->next; //temp is the head of 2 list while x is the head of 1st list
    x->next = NULL;
    y = reverse(temp); // reverses the 2nd half
    
    //Now, alternate merge 
    //cout<<temp->data<<"\n";
    x = head;
    struct Node *curr = newNode(0);
    head = curr;
    //cout<<curr->data<<endl;
    while(x || y){
        
        if(x){
            curr->next = x;
            //cout<<x->data<<endl;
            curr = curr->next;
            x = x->next;
        }
        
        if(y){
            curr->next = y;
            //cout<<y->data<<endl;
            curr = curr->next;
            y = y->next;
        }
    }
    
    head = head->next;
}
