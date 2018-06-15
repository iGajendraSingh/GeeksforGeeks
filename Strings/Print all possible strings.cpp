//Given a string str your task is to complete the function printSpaceString which takes only one argument 
//the string str and  prints all possible strings that can be made by placing spaces (zero or one) in between them. 

{
#include<bits/stdc++.h>
using namespace std;
void  printSpace(char str[]);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        printSpace(str);
        cout<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/
void printSpaceUtil(char str[], char buff[], int i, int j, int n){
    
    if(i==n){
        buff[j]='\0';
        cout<<buff<<"$";
        return;
    }
    
    buff[j] = str[i];
    printSpaceUtil(str,buff,i+1,j+1,n);
    
    buff[j]=' ';
    buff[j+1]=str[i];
    printSpaceUtil(str,buff,i+1,j+2,n);
}
/*You have to complete this function*/
void  printSpace(char str[])
{
//Your code here
    int n = strlen(str);
    
    char buff[2*n];
    buff[0] = str[0];
    printSpaceUtil(str,buff,1,1,n);
}
