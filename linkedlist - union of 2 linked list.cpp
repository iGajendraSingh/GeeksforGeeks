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
struct node* makeUnion(struct node* head1, struct node* head2);
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
        printList(makeUnion(a, b));
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
struct node* makeUnion(struct node* head1, struct node* head2)
{
    // code here
    map <int,int> m;
    struct node* temp = head1;
    
    while(temp!=NULL){
        if(m.find(temp->data)==m.end())
            m[temp->data]+=1;
        temp = temp->next;
    }
    
    temp = head2;
    while(temp!=NULL){
        if(m.find(temp->data)==m.end())
            m[temp->data]+=1;
        temp = temp->next;
    }
    struct node *root=NULL,*end;
    for(auto i=m.begin();i!=m.end();i++){
        struct node* curr = new node;
        curr->data = i->first;
        curr->next = NULL;
        if(root==NULL){
            root= curr;
            end = curr;
        }
        else{
            end->next = curr;
            end = end->next;
        }
    }
    return root;
}
