{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBST(root) << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST. 
   For example, return  value should be 1 for following tree.
         20
     /      \ 
   10       30
  and return value should be 0 for following tree.
         10
     /      \ 
   20       30 */
int isBSTUtil(struct Node* node, int min, int max){
    if(node==NULL)
        return 1;
    if(node->data <= min || node->data >max)
        return 0;
    
    if(isBSTUtil(node->left,min,node->data) && isBSTUtil(node->right,node->data,max))
        return 1;
    else
        return 0;
    
}
bool isBST(Node* root) {
    // Your code here
    int max = INT_MAX;
    int min = INT_MIN;
    return isBSTUtil(root,min,max);
}
