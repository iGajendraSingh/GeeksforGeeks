//The task is to complete the function  multiplyTwoLists which multiplies two linked lists l1 and l2 and returns their product . 
//The function takes two linked list l1, l2 as its arguments. 
//Note: The output could be large take modulo 10^9+7.
{
#include<bits/stdc++.h>
using namespace std;
 
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
 
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
 
 
 Node *reverse(Node **r)
{
    Node *prev =NULL;
    Node *cur = *r;
    Node *nxt;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}
/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}
void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {
        temp=Node;
        Node = Node->next;
        free(temp);
    }
}
 
/* Multiply contents of two linked lists */
long long  multiplyTwoLists (struct Node* , struct Node*);
 
// A utility function to print a linked list
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
 
/* Driver program to test above function */
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }
	     reverse(&first);
	     reverse(&second);
		 long long res = multiplyTwoLists(first,second);
	    	cout<<res<<endl;
freeList(first);
freeList(second);
   }
   return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Linked list node structure
struct Node
{
    int data;
    Node* next;
};*/
/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/
/*You are required to complete this method*/
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  struct Node *x = l1, *y = l2;
  long long int num1 = 0, num2 = 0, N = 1000000007;
  
  while(x!=NULL || y!=NULL){
      
      if(x){
          num1 = ((num1)%N*10)%N + x->data;
          x = x->next;
      }
      
      if(y){
          num2 = ((num2)%N*10)%N + y->data;
          y = y->next;
      }
  }
  return ((num1)%N*(num2)%N)%N;
}lni
