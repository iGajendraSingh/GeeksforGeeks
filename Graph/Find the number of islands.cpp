{
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000  
int findIslands(int A[MAX][MAX],int N,int M);
int main() {
	// your code goes here
	int T;
	cin>>T;
	int A[MAX][MAX];
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		memset(A,0,sizeof A);
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		cin>>A[i][j];
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/

bool isSafe(int A[][MAX], int row, int col, bool visited[MAX][MAX], int N, int M){
    
    return  (row>=0) && (row<N) && (col>=0) && (col<M) && 
    (A[row][col] && !visited[row][col]); 
}
void DFS(int A[][MAX],int row, int col, bool visited[MAX][MAX], int N, int M){
    static int rowNbr[] = {-1,-1,-1,0,0,1,1,1};
    static int colNbr[] = {-1,0,1,-1,1,-1,0,1};
    
    visited[row][col]= true;
    
    for(int k=0;k<8;k++){
        if(isSafe(A,row+rowNbr[k], col+ colNbr[k], visited,N,M))
            DFS(A,row+rowNbr[k], col+ colNbr[k], visited,N,M);
    }
}
int findIslands(int A[MAX][MAX], int N, int M)
{
//Your code here 
    bool visited[1000][1000];
    memset(visited,0,sizeof(visited));
    
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j] && !visited[i][j]){
                DFS(A,i,j,visited,N,M);
                count++;
            }
        }
    }
    
    return count;
}
