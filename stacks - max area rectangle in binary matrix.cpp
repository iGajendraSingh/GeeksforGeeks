//Given a binary matrix, Your task is to complete the function maxArea which the maximum size 
//rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument 
//is the Matrix M[ ] [ ] and the next two are two  integers n and m which denotes the size of the matrix M. 
//Your function should return an integer denoting the area of the maximum rectangle .
{
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int maxArea(int M[MAX][MAX],int n,int m);
int main()
{
    int T;
    cin>>T;
int M[MAX][MAX];
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<maxArea(M,n,m)<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/
int maxRect(int arr[], int n){
    stack <int> stk;
    int max_area = 0;
    int tp; //top of stack
    int area; //area with top element as the smallest bar
    
    int i=0;
    while(i<n){
        if(stk.empty() || arr[stk.top()]<=arr[i]){
            stk.push(i);
            i++;
        }
        
        else{
            int s = stk.top();
            stk.pop();
            area = arr[s]* ((stk.empty()) ? i : (i- stk.top()-1));
            
            if(max_area<area)
                max_area = area;
        }
    }
        
        while(!stk.empty()){
            int s = stk.top();
            stk.pop();
            area = arr[s] * ((stk.empty()) ? i : (i- stk.top()-1));
            if(max_area<area)
                max_area = area;
        }
    return max_area;
}
int maxArea(int M[MAX][MAX],int n,int m)
{
    //Your code here
    int result = maxRect(M[0],m);
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==1){
                M[i][j] = M[i-1][j] + 1;
            }
        }
        
        result = max(result,maxRect(M[i],m));
    }
    return result;
}
