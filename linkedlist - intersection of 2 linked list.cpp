
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
// struct node* intersection(struct node* a, struct node* b){
    
//     struct node* x;
//     struct node** localRef = &x;
    
//     while(a!=NULL && b!=NULL){
//         if(a->data == b->data){
//             push(localRef,a->data);
//             localRef = &((*localRef)->next);
//             a = a->next;
//             b = b->next;
//         }
//         else if(a->data < b->data){
//             a = a->next;
//         }
//         else{
//             b = b->next;
//         }
//     }
//     return x;
// }
// struct node* merge(struct node* a, struct node* b){
//     struct node* result = NULL;
//     if(a==NULL)
//         return b;
//     else if(b==NULL)
//         return a;

//     if(a->data <= b->data){
//         result = a;
//         result->next = merge(a->next,b);
//     }
//     else{
//         result = b;
//         result->next = merge(a,b->next);
//     }
//     return result;
// }
// void split(struct node* head, struct node** a, struct node** b){
//     struct node* slow = head;
//     struct node* fast = head->next;
    
//     while(fast!=NULL && fast->next!=NULL){
//         slow= slow->next;
//         fast = fast->next->next;
//     }
    
//     *a = head;
//     *b = slow->next;
//     slow->next = NULL;
// }
// void mergeSort(struct node **headRef){
//     struct node *head = *headRef;
//     struct node *a,*b;
//     if(head==NULL || head->next==NULL){
//         return;
//     }
//   split(head,&a,&b);
//   mergeSort(&a);
//   mergeSort(&b);
//   struct node *curr = merge(a,b);
// }
// struct node* findIntersection(struct node* head1, struct node* head2)
// {
//     // code here
//     mergeSort(&head1);
//     mergeSort(&head2);
//     struct node* temp = intersection(head1,head2);
//     return temp;
// }
struct node* findIntersection(struct node* head1, struct node* head2)
{
    struct node *p=head1,*q=head2,*root=NULL,*end;
    map <int,int> m;
    map <int,int> n;
    while(p!=NULL || q!=NULL)
    {
        if(p!=NULL)
        {
            m[p->data]++;
            p=p->next;
        }
        
        if(q!=NULL)
        {
            n[q->data]++;
            q=q->next;
        }
    }
    int min;
    for(auto i=m.begin();i!=m.end();i++)
    {
        if(n.find(i->first)!=n.end())
        {
            
            auto j=n.find(i->first);
            int min = ((i->second<j->second)?i->second:j->second);
            for(int k=1;k<=min;k++)
            {
                struct node *tmp=new node;
                tmp->data=i->first;
                tmp->next=NULL;
                if(root==NULL)
                {
                    root=tmp;
                    end=tmp;
                }
                else
                {
                    end->next=tmp;
                    end=end->next;
                }
            }
        }
    }
return root;
}
