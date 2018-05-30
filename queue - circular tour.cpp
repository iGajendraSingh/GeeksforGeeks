//Suppose there is a circle. There are n petrol pumps on that circle. You will be given two sets of data.
//1. The amount of petrol that every petrol pump has.
//2. Distance from that petrol pump to the next petrol pump.
//Your task is to complete the function tour which returns an integer denoting the first point from where a truck 
//will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity).
{
#include<bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump [],int );
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
   int start =0;
   int end = 1;
   int curr_petrol = p[start].petrol - p[start].distance;
   while(end!=start || curr_petrol<0){
       while(start!=end && curr_petrol<0){
           curr_petrol -= p[start].petrol - p[start].distance;
           start = (start+1)%n;
           
           if(start==0)
            return -1;
       }
       
       curr_petrol += p[end].petrol - p[end].distance;
       end = (end+1)%n;
   }
   return start;
}
