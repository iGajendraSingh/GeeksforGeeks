//Given a Linked List of integers, write a function to modify the linked list 
//such that all even numbers appear before all the odd numbers in the modified linked list. 
//Also, keep the order of even and odd numbers same.
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* next;
};

//adding elements to the end of the linked list
void append(struct node** head, int x){
    
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    
    struct node* last = *head;
    new_node->data = x;
    new_node->next = NULL;
    
    if(*head==NULL){
        *head = new_node;
        return;
    }
    
    while(last->next!=NULL)
        last = last->next;
    
    last->next = new_node;
    return;
}

void segregate(struct node* head){
    
    queue <int> q;
    struct node* prev = NULL;
    struct node* temp = head;
    struct node* curr;
    while(temp!=NULL){
        if((temp->data)%2==1){
            if(temp==head){
                q.push(temp->data);
                head = temp->next;
                curr = temp;
                temp = temp->next;
                free(curr);
            }
            else{
                q.push(temp->data);
                prev->next = temp->next;
                curr = temp;
                temp = temp->next;
                free(curr);
            }
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    
    while(!q.empty()){
        append(&head,q.front());
        q.pop();
    }
    
    while(head!=NULL){
        cout<<(head->data)<<" ";
        head=head->next;
    }
    cout<<"\n";
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n,x;
	    struct node* head = NULL;
	    cin>>n;
	    for(int i=0;i<n;i++){
	        cin>>x;
	        append(&head,x);
	        //cout<<1;
	    }
	    segregate(head);
	}
	return 0;
}
