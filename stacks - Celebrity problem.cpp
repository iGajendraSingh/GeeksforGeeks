//You are in a party of N people, where only one person is known to everyone. 
//Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. 
//Your task is to find the stranger (celebrity) in party.
//You will be given a square matrix M where if an element of row i and column j  is set to 1 
//it means there is an edge from ith person to jth person. An edge represent the relation that 
//i th person knows j th person. You need to complete the function getId which finds the id of the 
//celebrity if present else return -1. The function getId takes two arguments the square matrix M and its size n.
{
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int getId(int M[MAX][MAX],int n);
int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// The task is to complete this function
int knows(int M[MAX][MAX], int a, int b){
    return M[a][b];
}

int getId(int M[MAX][MAX], int n)
{
    //Your code here
    int a = 0;
    int b = n-1;
    
    while(a<b){
        if(knows(M,a,b))
            a++;
        else
            b--;
    }
    
    for(int i=0;i<n;i++){
        if(i!=a && (knows(M,a,i) || !knows(M,i,a)))
            return -1;
    }
    
    return a;
}
