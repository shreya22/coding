#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *node= new Node;
    node->data= data;
    node->left= NULL;
    node->right= NULL;
    return node;
}

int nodesCount(Node *root)
{
    if(root==NULL) return 0;
    return 1+ nodesCount(root->left) + nodesCount(root->right);
}

int depthOfTree(Node *root)
{
    if(root==NULL) return 0;
    return max(depthOfTree(root->left), depthOfTree(root->right))+1;
}

int balancedBinaryTree(Node *root)
{
    if(root==NULL) return 1;
    int currentDepth= depthOfTree(root);
    int expectedDepth= log(nodesCount(root))/log(2);

    if(abs(currentDepth - expectedDepth) > 1) return 0;
    return 1;
}

int main() {

    Node *root= newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    if(balancedBinaryTree(root)) cout<<"binary tree is balanced";
    else cout<<"unbalanced!";

    return 0;
}
