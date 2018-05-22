//Given a linked list, check if the the linked list has a loop. Linked list can contain self loop.
{
// C program to detect loop in a linked list
#include<stdio.h>
#include<stdlib.h>
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
          (struct node*) malloc(sizeof(struct node));
    /* put in the data  */
    new_node->data  = new_data;
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
int detectloop(struct node *list);
/* Drier program to test above function*/
int main()
{
	int t,n,c,x,i;
	scanf("%d",&t);
	while(t--){
    /* Start with the empty list */
    scanf("%d",&n);
    struct node *head = NULL;
    struct node* temp;
    struct node *s;
    scanf("%d",&x);
    push(&head,x);
    s=head;
    for(i=1;i<n;i++){
		scanf("%d",&x);
    push(&head,x);}
    /* Create a loop for testing */
   scanf("%d",&c);
    if(c>0){
    c=c-1;
    temp=head;
    while(c--)
    temp=temp->next;
    s->next=temp;
	}
	int g=detectloop(head);
    if(g)
    printf("True
");
    else
    printf("False
");
	}
    return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct node
{
int data;
node* next;
};*/
int detectloop(struct node *list){
// your code goes here
    struct node* x = list;
    struct node* y = list;
    
    while(x!=NULL && y!=NULL && x->next!=NULL){
        x= x->next->next;
        y= y->next;
        if(x==y)
            return 1;
    }
    
    return 0;
}
