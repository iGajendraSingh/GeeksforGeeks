//Design a data-structure SpecialStack (using the STL of stack) that supports all the stack operations like push(), 
//pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. 
//Your task is to complete all the functions, using stack data-Structure.
{
#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function(s) below*/
int minEle;
void push(int a)
{
     //add code here.
     if(s.empty()){
            s.push(a);
            minEle = a;
     }
     
     if(a<minEle){
         s.push(2*a-minEle);
         minEle = a;
     }
     else
        s.push(a);
}
bool isFull(int n)
{
     //add code here.
     if(s.size()==n)
        return true;
     else
        return false;
}
bool isEmpty()
{
    //add code here.
    if(s.empty())
        return true;
    else
        return false;
}
int pop()
{
    //add code here.
    int t = s.top();
    s.pop();
    
    if(t<minEle){
         int x = minEle;
         minEle = 2*minEle - t;
         return x;
    }
    else
       return t; 
}
int getMin()
{
   //add code here.
   if(s.empty())
    return -1;
   else
    return minEle;
}
