//Given two linked lists, your task is to complete the function findIntersection, that returns the intersection of two linked lists.
{
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("
");
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	(struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
struct node* findIntersection(struct node* head1, struct node* head2);
int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(findIntersection(a, b));
    }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
bool isPresent(struct node* head1, int x){
    struct node* temp  = head1;
    while(temp!=NULL){
        if(temp->data = x)
            return true;
        temp= temp->next;
    }
    return false;
}
struct node* findIntersection(struct node* head1, struct node* head2)
{
    // code here
    struct node* result =NULL;
    while(head2!=NULL){
        if(isPresent(head1,head2->data)){
            push(&result,head2->data);
        }
        head2= head2->next;
    }
    
    return result;
}
