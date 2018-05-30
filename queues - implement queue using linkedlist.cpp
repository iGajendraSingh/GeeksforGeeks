{
#include<bits/stdc++.h>
using namespace std;
struct QueueNode
{
    int data;
    QueueNode *next;
};
class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
public :
    void push(int);
    int pop();
};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue *sq = new Queue();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";
        }
        }
        cout<<endl;
    }
    }

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* 
The structure of the node of the queue is
struct QueueNode
{
    int data;
    QueueNode *next;
};
and the structure of the class is
class Queue {
private:
    QueueNode *front;
    QueueNode *rear;
public :
    void push(int);
    int pop();
};
 */
/* The method push to push element into the queue*/
void Queue:: push(int x)
{
        // Your Code
    
        struct QueueNode* temp = (QueueNode*)malloc(sizeof(struct QueueNode));
        temp->data = x;
        temp->next = NULL;
        if(front==NULL && rear==NULL)
            front = rear = temp;
        else{
            rear->next = temp;
            rear = temp;
        }
        return;
}
/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
        // Your Code
        if(front==NULL){
            //rear = NULL;
            return -1;
        }
            
        struct QueueNode* curr = front;
        int x = front->data;
        front = front->next;
        free(curr);
        if(front==NULL)
            rear = NULL;
        return x;
}
