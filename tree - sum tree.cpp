//Write a function that returns true if the given Binary Tree is SumTree else false. 
//A SumTree is a Binary Tree where value of every node x is equal to sum of nodes present in its left subtree and right subtree of x. 
//An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.
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
bool isSumTree(struct Node* node);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
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
     cout << isSumTree(root) << endl;
  }
  return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
int isSum(Node* root){
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return root->data;
    else{
        if(root->data != (isSum(root->left) + isSum(root->right)))
            return 0;
        else    
            return 2*root->data;
    }
}
// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root){
// Your code here
    if(root==NULL)
        return 1;
    return isSum(root);
}
